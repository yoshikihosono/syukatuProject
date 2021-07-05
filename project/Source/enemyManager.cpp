#include "enemyManager.h"
#include "furball.h"
#include "playScene.h"

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
		return; // �Q�[�����J�n����O�ȂǁA�����Ȃ����́AUpdate���s��Ȃ�

	for (auto it = enemies.begin(); it != enemies.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) { // �폜���v�����ꂽ�̂�
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