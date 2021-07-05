#include "bootScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"

BootScene::BootScene()
{
	SceneBase* common = SceneManager::CommonScene();
	DebugScreen* ds = common->CreateGameObject<DebugScreen>();
	common->SetDrawOrder(ds, 10000);
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TitleScene"); // �N�����I�������Title��\��
}

void BootScene::Draw()
{
}
