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
	int _hp, int _bulletKind, int _waitTime, int _stagnationTime, int _itemKind, EnemyBase* _boss) : EnemyBase(scene)
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
	specialAttack = false;

	itM = GetScene()->FindGameObject<ItemManager>();
	efM = GetScene()->FindGameObject<EfectManager>();
	eM = GetScene()->FindGameObject<EnemyManager>();
	pl = GetScene()->FindGameObject<Player>();
	boss = _boss;
	bPosition = boss->GetPosition();
	beforeBossPos = boss->GetPosition();
}

VShaped_MINIONS::~VShaped_MINIONS()
{
	DeleteGraph(hImage);
	boss = nullptr;
}

void VShaped_MINIONS::Update()
{
	bPosition = boss->GetPosition();
	base_angle = HomingBoss(bPosition);

	if (hp == 0) {
		efM->Create(position, 0, 0, 10, 0.5f, 0.5f, Efect::ColorPalette::white);
		itM->Create(position, itemKind);
		DestroyMe();
	}

	if (position.x + WIDTH < 250 || position.x > 1175 || position.y + HEIGHT < -200 || position.y > 1040) {
		DestroyMe();
	}

	position.x = position.x + cos(base_angle) * 3;
	position.y = position.y + sin(base_angle) * 3;

	cnt++;
	//position.x += velocity.x * speed;
	//position.y += velocity.y * speed;
	beforeBossPos = boss->GetPosition();
}

void VShaped_MINIONS::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 0, 0, 40, 40, hImage, true);
}

bool VShaped_MINIONS::Collision(Vector2 center, float radius) const
{
	if (hp == 0)
		return false;

	float dx = (position.x + CENTER_X) - center.x;
	float dy = (position.y + CENTER_Y) - center.y;
	return (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS));
}

void VShaped_MINIONS::AddDamage(int damage)
{
	hp -= damage;
	if (hp < 0) {
		hp = 0;
	}
}

void VShaped_MINIONS::setBoss(EnemyBase * _e)
{
	boss = _e;
}

double VShaped_MINIONS::HomingBoss(Vector2 _bPos)
{
	return atan2((float)_bPos.y - beforeBossPos.y, (float)_bPos.x - beforeBossPos.x);
}
