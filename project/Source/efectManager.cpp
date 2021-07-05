#include "efectManager.h"

EfectManager::EfectManager(SceneBase * scene) : GameObject (scene)
{
	efects.clear();
}

EfectManager::~EfectManager()
{
	for (auto it = efects.begin(); it != efects.end();) {
		delete (*it);
		it = efects.erase(it);
	}
	efects.clear();
}

void EfectManager::Update()
{
	for (auto it = efects.begin(); it != efects.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) {
			delete(*it);
			it = efects.erase(it);
		}
		else
			it++;
	}

	for (auto& ef : efects) {
		ef->Update();
	}
}

void EfectManager::Draw()
{
	for (auto& ef : efects) {
		ef->Draw();
	}
}

void EfectManager::Create(Vector2 pos, int _pattern, int _drawPattern, float _valueSpeed, float _sizeSpeed, float firstSize, int _color)
{
	Efect* ef = new Efect(GetScene(), pos, _pattern, _drawPattern, _valueSpeed, _sizeSpeed, firstSize, _color);
	if (ef != nullptr)
		efects.emplace_back(ef);
}
