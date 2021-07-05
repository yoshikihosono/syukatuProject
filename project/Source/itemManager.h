#pragma once
//itemManager.h
#include "..//Library/gameObject.h"
#include "itemBase.h"

class ItemManager : public GameObject {
public:
	ItemManager(SceneBase* scene);
	~ItemManager();
	void Update();
	void Draw();

	enum ITEM_TYPE {
		NONE = 0,
		POWERUP,
		SCORE,
		BOMB,
		EXTEND,
	};

	void Create(Vector2 _pos, int _itemKind);
	int Collision(Vector2 center, float radius);
private:
	std::list<ItemBase*> items;
	int itemKind;
};