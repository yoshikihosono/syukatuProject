#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"
#include "player.h"

class EnemyBarrage : public GameObject {
public:
	EnemyBarrage(SceneBase* _scene, Vector2 _pos, double _base_angle, int _bulletMax, Vector2 _playerPos, int _bulletKind, int _bulletColor, float _speed);
	virtual ~EnemyBarrage();
	virtual void Update();
	virtual void Draw();
	virtual bool Collision(Vector2 center, float radius) const;	//�v���C���[�Ƃ̓����蔻��
private:
	/*struct Bullet
	{
		Vector2 position;
		bool flag;
		int hImage;
		float angle;
		bool first;
		int cnt;
		float spd;
		int state;
	};
	Bullet bullet[1000];*/

	Vector2 position;
	bool flag;
	//int hImage;
	float angle;
	bool first;
	float spd;
	int state;

	double base_angle;
	int pattern;
	int cnt;
	int bulletMax;
	int bulletKind;
	int HEIGHT, WIDTH;
	int CENTER_X, CENTER_Y;
	int RADIUS;
	int bulletColor;
	int interval;
	float coolTime;

	Vector2 plPos;
public:
	enum hImage_ID {
		dotbullet = 0,
		smallbullet1,
		smallbullet2,
		mediumbullet,
		largebullet,
		ricegrainbullet,
		MAX
	};
	int hImage[hImage_ID::MAX];	//�G�̒e�̉摜�n���h��

	enum ColorPalette {
		white = 0,
		red,
		green,
		blue,
	};
	ColorPalette colorPalette;
};