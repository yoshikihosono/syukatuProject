#include "enemyBarrageManager.h"
#include "player.h"
#include "playScene.h"

EnemyBarrageManager::EnemyBarrageManager(SceneBase* scene)
{
	barrages.clear();
}

EnemyBarrageManager::~EnemyBarrageManager()
{
	for (auto it = barrages.begin(); it != barrages.end();) {
		delete (*it);
		it = barrages.erase(it);
	}
	barrages.clear();
}

void EnemyBarrageManager::Update()
{
	for (auto it = barrages.begin(); it != barrages.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) {
			delete(*it);
			it = barrages.erase(it);
		}
		else
			it++;
	}

	for (auto& eb : barrages) {
		eb->Update();
	}
}

void EnemyBarrageManager::Draw()
{
	for (auto& eb : barrages) {
		eb->Draw();
	}
}

void EnemyBarrageManager::Create(Vector2 pos, double _base_angle,int _bulletMax,int _bulletKind,int _bulletColor, float _speed)
{
	EnemyBarrage* eb = new EnemyBarrage(GetScene(), pos, _base_angle, _bulletMax, playerPosition, _bulletKind, _bulletColor, _speed);
	if (eb != nullptr)
		barrages.emplace_back(eb);
}

void EnemyBarrageManager::GetPlayerPosition(Vector2 pos)
{
	playerPosition = pos;
}

bool EnemyBarrageManager::Collision(Vector2 center, float radius)
{
	for (auto eb : barrages) {
		if (eb->Collision(center, radius))
			return true;
	}
	return false;
}