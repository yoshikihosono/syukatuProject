#include "itemManager.h"
#include "powerupItem.h"
#include "scoreItem.h"

ItemManager::ItemManager(SceneBase* scene) : GameObject(scene)
{
	items.clear();
}

ItemManager::~ItemManager()
{
	for (auto it = items.begin(); it != items.end();) {
		delete (*it);
		it = items.erase(it);
	}
	items.clear();
}

void ItemManager::Update()
{
	for (auto it = items.begin(); it != items.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) {
			delete(*it);
			it = items.erase(it);
		}
		else
			it++;
	}

	for (auto& it : items) {
		it->Update();
	}
}

void ItemManager::Draw()
{
	for (auto& it : items) {
		it->Draw();
	}
}

void ItemManager::Create(Vector2 _pos, int _itemKind)
{
	ItemBase* it = nullptr;
	itemKind = _itemKind;
	switch (_itemKind)
	{
	case POWERUP: it = new PowerupItem(GetScene(), _pos); break;
	case   SCORE: it = new ScoreItem(GetScene(), _pos);	  break;
	}
	it->itemKind = _itemKind;

	if (it != nullptr)
		items.emplace_back(it);
}

int ItemManager::Collision(Vector2 center, float radius)
{
	for (auto it : items) {
		if (it->Collision(center, radius))
			return it->itemKind;
	}
	return false;
}
