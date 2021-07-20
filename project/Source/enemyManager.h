#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"

class EnemyBase;
class VShaped_BOSS;

class EnemyManager : public GameObject {
public:
	EnemyManager(SceneBase* scene);
	~EnemyManager();
	void Update()override;
	void Draw() override;

	enum ENEMY_TYPE {
		FURBALL,	//ñ—ã 
		FAIRY,	//ódê∏
		VSHAPED,	//Véöå^ÇÃï“ë‡
	};

	void Create(ENEMY_TYPE type,int x,			int y,			int cnt,			int pattern,
				float speed,	int barrageTime,int maxBullet,	int barrageKind,	int color,		
				int hp,			int bulletKind, int waitTime,	int stagnationTime, int itemKind);

	EnemyBase* Collision(Vector2 center, float radius) const;

private:
	std::list<EnemyBase*> enemies;
};