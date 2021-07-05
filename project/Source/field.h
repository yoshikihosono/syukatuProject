#pragma once
#include "vector2.h"
#include "../Library/gameObject.h"

class Field : public GameObject {
public:
	Field(SceneBase* scene);
	~Field();
	void Start() override;
	void Draw() override;
};