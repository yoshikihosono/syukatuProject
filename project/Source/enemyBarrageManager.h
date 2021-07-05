#pragma once
#include "..//Library/gameObject.h"
#include "enemyBarrage.h"
#include "player.h"
class EnemyBarrage;

class EnemyBarrageManager : public GameObject {
public:
	EnemyBarrageManager(SceneBase* scene);
	~EnemyBarrageManager();
	void Update() override;
	void Draw() override;
	void Create(Vector2 pos, double _base_angle,int _bulletMax, int _bulletKind, int _bulletColor, float _speed);
	void GetPlayerPosition(Vector2 pos);
	bool Collision(Vector2 center, float radius);
private:
	std::list<EnemyBarrage*> barrages;
	Vector2 playerPosition;
};