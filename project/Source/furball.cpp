#include "furball.h"
#include <assert.h>
#include "enemyBarrageManager.h"

namespace {
	static const int CENTER_X = 20;
	static const int CENTER_Y = 20;
	static const int WIDTH = 40;
	static const int HEIGHT = 40;
	static const int RADIUS = 20;
}

Furball::Furball(SceneBase* scene, int _x, int _y, int _cnt, int _pattern,
	float _speed, int _barrageTime, int _maxBullet, int _barrageKind, int _color,
	int _hp, int _bulletKind, int _waitTime, int _stagnationTime, int _itemKind) : EnemyBase(scene)
{
	position = Vector2(_x, _y);
	hImage = LoadGraph("data\\texture\\furball.png");
	assert(hImage > 0);
	cnt				= _cnt;
	pattern			= _pattern;
	speed			= _speed;
	barrageTime		= _barrageTime;
	maxBullet		= _maxBullet;
	barrageKind		= _barrageKind;
	color			= _color;
	hp				= _hp;
	bulletKind		= _bulletKind;
	waitTime		= _waitTime;
	stagnationTime	= _stagnationTime;
	itemKind		= _itemKind;
	shotFlag		= false;

	eBM = GetScene()->FindGameObject<EnemyBarrageManager>();
	efM = GetScene()->FindGameObject<EfectManager>();
	itM = GetScene()->FindGameObject<ItemManager>();
	eSM = GetScene()->FindGameObject<EnemyShotManager>();
	pl = GetScene()->FindGameObject<Player>();
}

Furball::~Furball()
{
	DeleteGraph(hImage);
}

void Furball::Update()
{
	if (hp == 0) {
		efM->Create(position, 0, 0, 10, 0.5f, 0.5f, Efect::ColorPalette::white);
		itM->Create(position, itemKind);
		DestroyMe();
	}

	if (position.x + WIDTH < 310 || position.x > 1175 || position.y + HEIGHT < -40 || position.y > 1040) {
		DestroyMe();
	}

	switch (pattern)
	{
	case 0: MovePattern_0(); break;	//下に移動、一定時間止まって上に戻る
	case 1: MovePattern_1(); break;	//下に移動、一定時間止まって左下に進む
	case 2: MovePattern_2(); break;	//下に移動、一定時間止まって右下に進む
	case 3: MovePattern_3(); break;	//下に移動、即座に左下に進む
	case 4: MovePattern_4(); break;	//下に移動、即座に右下に進む
	case 5: MovePattern_5(); break;	//
	}

	cnt++;
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
}

void Furball::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 0, 0, 40, 40, hImage, true);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", cnt);
}

bool Furball::Collision(Vector2 center, float radius) const
{
	if (hp == 0)
		return false;

	float dx = (position.x + CENTER_X) - center.x;
	float dy = (position.y + CENTER_Y) - center.y;
	return (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS));
}

void Furball::AddDamage(int damage)
{
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
}

void Furball::MovePattern_0()
{
	if (cnt == waitTime)
		velocity.y = 3;

	if (cnt == waitTime + 60) {
		velocity.y = 0;
		//eBM->Create(position, maxBullet, barrageKind, bulletKind, color);
		eSM->Create(position, maxBullet, barrageKind, bulletKind, color);
	}

	if (cnt == waitTime + 60 + stagnationTime)
		velocity.y = -2;
}

void Furball::MovePattern_1()
{
	if (cnt == waitTime)
		velocity.y = 3;

	if (cnt == waitTime + 60)
		velocity.y = 0;

	if (cnt == waitTime + 60 + stagnationTime) {
		velocity.y = 3;
		velocity.x = -1;
	}
}

void Furball::MovePattern_2()
{
	if (cnt == waitTime)
		velocity.y = 3;

	if (cnt == waitTime + 60)
		velocity.y = 0;

	if (cnt == waitTime + 60 + stagnationTime) {
		velocity.y = 3;
		velocity.x = 1;
	}
}

void Furball::MovePattern_3()
{
	if (cnt == waitTime)
		velocity.y = 5;

	if (cnt == waitTime + 60) {
		velocity.y -= 5 / 50;
		velocity.x -= 5;
		//eBM->Create(position, maxBullet, barrageKind, bulletKind, color);
		eSM->Create(position, maxBullet, barrageKind, bulletKind, color);
	}

	/*if (cnt == waitTime + 65) {
		eBM->Create(position);
	}

	if (cnt == waitTime + 70) {
		eBM->Create(position);
	}*/
}

void Furball::MovePattern_4()
{
	if (cnt == waitTime)
		velocity.y = 5;

	if (cnt == waitTime + 60) {
		velocity.y -= 5 / 50;
		velocity.x += 5;
		//eBM->Create(position, maxBullet, barrageKind, bulletKind, color);
	}
}

void Furball::MovePattern_5()
{

}
