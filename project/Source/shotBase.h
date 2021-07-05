#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"

class ShotBase : public GameObject
{
public:
	ShotBase(SceneBase* _scene, Vector2 _pos);
	~ShotBase();
	virtual void Update() override;
	virtual void Draw() override;
private:
	Vector2 position;	//ç¿ïW
	const int sHeight = 20;
	const int sWidth = 20;
	const int speed = 10;
	int hImage;
	bool exist;
	float value;
	Vector2 hitPosition;
	float size;
	int efectImage;
};