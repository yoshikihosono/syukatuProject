#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"

class ItemBase : public GameObject {
public:
	ItemBase(SceneBase* _scene) {};
	virtual ~ItemBase() {};
	virtual void Update() override {};
	virtual void Draw() override {};
	virtual bool Collision(Vector2 center, float radius) { return false; };
	int itemKind;
};