#include "vShaped_BOSS.h"
#include <assert.h>

namespace {
	static const int CENTER_X = 20;
	static const int CENTER_Y = 20;
	static const int WIDTH = 40;
	static const int HEIGHT = 40;
	static const int RADIUS = 20;
}

VShaped_BOSS::VShaped_BOSS(SceneBase* scene, int _x, int _y, int _cnt, int _pattern,
						   float _speed, int _barrageTime, int _maxBullet, int _barrageKind, int _color,
						   int _hp, int _bulletKind, int _waitTime, int _stagnationTime, int _itemKind) : EnemyBase(scene){
	position = Vector2(_x, _y);
	hImage = LoadGraph("data\\texture\\furball.png");
	assert(hImage > 0);
	cnt = _cnt;
	pattern = _pattern;
	speed = _speed;
	barrageTime = _barrageTime;
	maxBullet = _maxBullet;
	barrageKind = _barrageKind;
	color = _color;
	hp = _hp;
	bulletKind = _bulletKind;
	waitTime = _waitTime;
	stagnationTime = _stagnationTime;
	itemKind = _itemKind;
	shotFlag = false;

	eBM = GetScene()->FindGameObject<EnemyBarrageManager>();
	efM = GetScene()->FindGameObject<EfectManager>();
	itM = GetScene()->FindGameObject<ItemManager>();
	eSM = GetScene()->FindGameObject<EnemyShotManager>();
	pl = GetScene()->FindGameObject<Player>();
}

VShaped_BOSS::~VShaped_BOSS()
{
	DeleteGraph(hImage);
}

void VShaped_BOSS::Update()
{
	if (hp == 0) {
		efM->Create(position, 0, 0, 10, 0.5f, 0.5f, Efect::ColorPalette::white);
		itM->Create(position, itemKind);
		DestroyMe();
	}

	if (position.x + WIDTH < 310 || position.x > 1175 || position.y + HEIGHT < -40 || position.y > 1040) {
		DestroyMe();
	}

	//switch (pattern)
	//{
	//case 0: MovePattern_0(); break;	//â∫Ç…à⁄ìÆÅAàÍíËéûä‘é~Ç‹Ç¡Çƒè„Ç…ñﬂÇÈ
	//}

	velocity.y = 3;

	cnt++;
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
}

void VShaped_BOSS::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 0, 0, 40, 40, hImage, true);
}

bool VShaped_BOSS::Collision(Vector2 center, float radius) const
{
	if (hp == 0)
		return false;

	float dx = (position.x + CENTER_X) - center.x;
	float dy = (position.y + CENTER_Y) - center.y;
	return (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS));
}

void VShaped_BOSS::AddDamage(int damage)
{
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
}

void VShaped_BOSS::MovePattern_0()
{
	if (cnt == waitTime)
		velocity.y = 3;
}

Vector2 VShaped_BOSS::GetPosition()
{
	return position;
}


