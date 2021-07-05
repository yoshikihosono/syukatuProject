#pragma once
#include "..//Library/gameObject.h"

class BackGround : public GameObject 
{
public:
	BackGround(SceneBase* scene);
	~BackGround();
	void Update();
	void Draw();
private:
	int hImage;
	const float X = 310;
	float firstY, secondY;
};