#pragma once
//shotManager.h
#include "..//Library/gameObject.h"
#include "shotBase.h"

class ShotManager : public GameObject{
public:
	ShotManager(SceneBase* _scene);
	~ShotManager();
	void Update() override;
	void Draw() override;
	void Spawn(Vector2 _pos);
private:
	std::list<ShotBase*> shots;
};