#include "enemyShot.h"
#include "enemyBarrageManager.h"

namespace {
	static const double PI = 3.1415926535898;
	static const double PI2 = 3.1415926535898 * 2;

	double rang(double, float _ang) {
		return (-_ang + _ang * 2 * GetRand(10000) / 10000.0);
	}
}

EnemyShot::EnemyShot(SceneBase* _scene, Vector2 _pos, int _maxbullet, int _barrageKind, int _bulletKind, int _bulletColor) : GameObject(_scene) {
	base_position = _pos;
	bulletMax = _maxbullet;
	pattern = _barrageKind;
	bulletKind = _bulletKind;
	bulletColor = _bulletColor;
	speed = 3;
	coolTime = 0;

	first = true;

	eBM = GetScene()->FindGameObject<EnemyBarrageManager>();
	pl = GetScene()->FindGameObject<Player>();
	plPos = pl->GetPosition();
}

EnemyShot::~EnemyShot() {
}

void EnemyShot::Update() {
	switch (pattern) {
	case 0: ShotPattern_0(); break;
	case 1: ShotPattern_1(); break;
	case 2: ShotPattern_2(); break;
	case 3: ShotPattern_3(); break;
	case 4: ShotPattern_4(); break;
	default:break;
	}

	if (first == true) {
		for (int i = 0; i < bulletMax; i++) {
			eBM->Create(base_position, base_angle, bulletMax, bulletKind, bulletColor, speed);
		}
		first = false;
	}
}

void EnemyShot::Draw()
{
}

void EnemyShot::ShotPattern_0() {
	//ŠgŽU’e
	for (int i = 0; i < bulletMax; i++) {
		base_angle = (360 / bulletMax) * i * (DX_PI / 180);
	}
}

void EnemyShot::ShotPattern_1() {
	//ƒz[ƒ~ƒ“ƒO
	base_angle = Shotatan2(base_position);
}

void EnemyShot::ShotPattern_2() {
}

void EnemyShot::ShotPattern_3() {
}

void EnemyShot::ShotPattern_4() {
}

double EnemyShot::Shotatan2(Vector2 _position) {
	return atan2((float)plPos.y - _position.y, (float)plPos.x - _position.x);
}

double EnemyShot::Rang(double ang) {
	return (-ang + ang * 2 * GetRand(10000) / 10000.0);
}

void EnemyShot::Create()
{
}
