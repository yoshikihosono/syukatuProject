#include "enemyManager.h"
#include "furball.h"
#include "playScene.h"
#include "vShaped_BOSS.h"
#include "vShaped_MINIONS.h"

EnemyManager::EnemyManager(SceneBase * scene) : GameObject(scene)
{
	enemies.clear();
}

EnemyManager::~EnemyManager()
{
	for (auto it = enemies.begin(); it != enemies.end(); ) {
		delete (*it);
		it = enemies.erase(it);
	}
	enemies.clear();
}

void EnemyManager::Update()
{
	PlayScene* scene = dynamic_cast<PlayScene*>(GetScene());
	if (scene != nullptr && !scene->CanMove())
		return; // ゲームを開始する前など、動けない時は、Updateを行わない

	for (auto it = enemies.begin(); it != enemies.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) { // 削除が要求されたので
			delete (*it);
			it = enemies.erase(it);
		}
		else
			it++;
	}
}

void EnemyManager::Draw()
{
	for (auto e : enemies)
		e->Draw();
}

void EnemyManager::Create(ENEMY_TYPE type,	int x,			int y,			int cnt,			int pattern,	
						  float speed,		int barraeTime,	int maxBullet,	int barrageKind,	int color,
						  int hp,			int bulletKind, int waitTime,	int stagnationTime,	int itemKind)
{
	EnemyBase* e = nullptr;
	switch (type) {
	case FURBALL:
		e = new Furball(GetScene(), x, y, cnt, pattern, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
			break;
	case FAIRY:
		break;
	case VSHAPED:
		//親分
		e = new VShaped_BOSS(GetScene(), x, y, cnt, pattern, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
		//子分
		e = new VShaped_MINIONS(GetScene(), x - 30, y - 30, cnt, 1, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
		e = new VShaped_MINIONS(GetScene(), x - 60, y - 60, cnt, 2, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
		e = new VShaped_MINIONS(GetScene(), x + 30, y - 30, cnt, 3, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
		e = new VShaped_MINIONS(GetScene(), x + 60, y - 60, cnt, 4, speed, barraeTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind);
		break;
	}

	if (e != nullptr)
		enemies.emplace_back(e);
}

EnemyBase * EnemyManager::Collision(Vector2 center, float radius) const
{
	for (auto e : enemies) {
		if (e->Collision(center, radius))
			return e;
	}
	return nullptr;
}
