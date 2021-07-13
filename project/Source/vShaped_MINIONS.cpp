#include "vShaped_MINIONS.h"
#include <assert.h>

namespace {
	static const int CENTER_X = 20;
	static const int CENTER_Y = 20;
	static const int WIDTH = 40;
	static const int HEIGHT = 40;
	static const int RADIUS = 20;
}

VShaped_MINIONS::VShaped_MINIONS(SceneBase* scene, int _x, int _y, int _cnt, int _pattern,
	float _speed, int _barrageTime, int _maxBullet, int _barrageKind, int _color,
	int _hp, int _bulletKind, int _waitTime, int _stagnationTime, int _itemKind) : EnemyBase(scene)
{
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

	boss = scene->FindGameObject<VShaped_BOSS>();
	bPosition = boss->GetPosition();
}

VShaped_MINIONS::~VShaped_MINIONS()
{
	DeleteGraph(hImage);
}

void VShaped_MINIONS::Update()
{
	if (GetScene()->FindGameObject<VShaped_BOSS>() != NULL) {
		boss = GetScene()->FindGameObject<VShaped_BOSS>();
		bPosition = boss->GetPosition();
	}

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
	case 1:

		position.x = bPosition.x - 30;
		position.y = bPosition.y - 30;

		break;

	case 2:

		position.x = bPosition.x - 60;
		position.y = bPosition.y - 60;

		break;

	case 3:

		position.x = bPosition.x + 30;
		position.y = bPosition.y - 30;

		break;

	case 4:

		position.x = bPosition.x + 60;
		position.y = bPosition.y - 60;

		break;
	}

	cnt++;
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
}

void VShaped_MINIONS::Draw()
{
}

bool VShaped_MINIONS::Collision(Vector2 center, float radius) const
{
	return false;
}

void VShaped_MINIONS::AddDamage(int damage)
{
}