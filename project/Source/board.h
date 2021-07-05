#pragma once
#include "../Library/gameObject.h"

class Board : public GameObject {
public:
	Board(SceneBase* _scene);
	~Board();
	void Update();
	void Draw();
private:
	int hImage;
};