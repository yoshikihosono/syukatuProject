#pragma once
#include "..//Library/gameObject.h"
#include "enemyShot.h"

class EnemyShot;

class EnemyShotManager : public GameObject {
public:
	EnemyShotManager(SceneBase* _scene);
	~EnemyShotManager();
	void Update();
	void Draw();
	void Create(Vector2 _pos, int _maxbullet, int _barrageKind, int _bulletKind, int _bulletColor);

private:
	std::list<EnemyShot*> shots;
};