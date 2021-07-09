#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"
#include "enemyBarrage.h"
#include "enemyBarrageManager.h"
#include "player.h"

class EnemyShot : public GameObject {
public:
	EnemyShot(SceneBase* _scene, Vector2 _pos, int _maxbullet, int _barrageKind, int _bulletKind, int _bulletColor);
	~EnemyShot();
	void Update();
	void Draw();
	void ShotPattern_0();
	void ShotPattern_1();
	void ShotPattern_2();
	void ShotPattern_3();
	void ShotPattern_4();
	double Shotatan2(Vector2 _position);
	double Rang(double ang);
	void Create();
private:
	Vector2 base_position;
	double base_angle;
	int pattern;
	int cnt;
	int bulletMax;
	int bulletKind;
	int bulletColor;
	int interval;
	float coolTime;
	float speed;
	bool first;

	Vector2 plPos;
	EnemyBarrageManager* eBM;
	Player* pl;
};