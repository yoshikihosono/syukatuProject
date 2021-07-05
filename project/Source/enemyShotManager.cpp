#include "enemyShotManager.h"

EnemyShotManager::EnemyShotManager(SceneBase * _scene) : GameObject(_scene)
{
	shots.clear();
}

EnemyShotManager::~EnemyShotManager()
{
	for (auto it = shots.begin(); it != shots.end();) {
		delete (*it);
		it = shots.erase(it);
	}
	shots.clear();
}

void EnemyShotManager::Update()
{
	for (auto it = shots.begin(); it != shots.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) {
			delete(*it);
			it = shots.erase(it);
		}
		else
			it++;
	}

	for (auto& eS : shots) {
		eS->Update();
	}
}

void EnemyShotManager::Draw()
{
}

void EnemyShotManager::Create(Vector2 _pos, int _maxbullet, int _barrageKind, int _bulletKind, int _bulletColor)
{
	EnemyShot* eS = new EnemyShot(GetScene(), _pos, _maxbullet, _barrageKind, _bulletKind, _bulletColor);
	if (eS != nullptr) {
		shots.emplace_back(eS);
	}
}
