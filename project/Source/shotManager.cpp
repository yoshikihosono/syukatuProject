#include "shotManager.h"

ShotManager::ShotManager(SceneBase * _scene) : GameObject (_scene)
{
	shots.clear();
}

ShotManager::~ShotManager()
{
	for (auto it = shots.begin(); it != shots.end();) {
		delete (*it);
		it = shots.erase(it);
	}
	shots.clear();
}

void ShotManager::Update()
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

	for (auto& s : shots) {
		s->Update();
	}
}

void ShotManager::Draw()
{
	for (auto& s : shots) {
		s->Draw();
	}
}

void ShotManager::Spawn(Vector2 _pos)
{
	ShotBase* s = new ShotBase(GetScene(), _pos);
	if (s != nullptr)
		shots.emplace_back(s);
}
