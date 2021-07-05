#pragma once
#include "itemBase.h"

class PowerupItem : public ItemBase {
public:
	PowerupItem(SceneBase* _scene, Vector2 _position);
	~PowerupItem();
	void Update() override;
	void Draw() override;
	bool Collision(Vector2 center, float radius) override;
private:
	Vector2 position;
	Vector2 velocity;
	int hImage;
	bool exist;
	int cnt;
};