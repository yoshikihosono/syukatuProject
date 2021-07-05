#include "powerupItem.h"
#include <assert.h>
#include "debugScreen.h"

namespace {
	static const int CENTER_X = 16;
	static const int CENTER_Y = 16;
	static const int RADIUS = 16;
}

PowerupItem::PowerupItem(SceneBase* _scene,Vector2 _position) : ItemBase(_scene)
{
	position = _position;
	hImage = LoadGraph("data\\texture\\item\\powerupItem.png");
	assert(hImage > 0);
	velocity.y = -2;
	exist = true;
}

PowerupItem::~PowerupItem()
{
}

void PowerupItem::Update()
{
	if (position.y > 1080) {
		exist = false;
	}

	if (!exist)
		DestroyMe();

	if (cnt == 60)
		velocity.y = 0;

	if (cnt == 70)
		velocity.y = 2;

	position.y += velocity.y;
	cnt++;
}

void PowerupItem::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}

bool PowerupItem::Collision(Vector2 center, float radius)
{
	float dx = (position.x + CENTER_X) - center.x;
	float dy = (position.y + CENTER_Y) - center.y;
	if (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS)) {
		exist = false;
		return true;
	}
	return false;
}
