#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "player.h"
#include "background.h"
#include "shotManager.h"
#include "board.h"
#include "enemyManager.h"
#include "field.h"
#include "furball.h"
#include "efectManager.h"
#include "enemyBarrageManager.h"
#include "itemManager.h"
#include "enemyShotManager.h"

PlayScene::PlayScene()
{
	CreateGameObject<BackGround>();
	CreateGameObject<Field>();
	CreateGameObject<EfectManager>();
	CreateGameObject<EnemyManager>();
	CreateGameObject<EnemyBarrageManager>();
	CreateGameObject<EnemyShotManager>();
	CreateGameObject<ShotManager>();
	CreateGameObject<ItemManager>();
	CreateGameObject<Player>();
	CreateGameObject<Board>();
	state = BEFORE_PLAY;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}

	counter++;
	switch (state) {
	case BEFORE_PLAY:
		if (counter >= 180) {
			PlaySoundMem(bgmSound, DX_PLAYTYPE_LOOP);
			state = IN_PLAY;
			counter = 0;
		}
		break;
	case IN_PLAY:
		
		break;
	case CLEAR:
		break;
	case GAMEOVER:
		break;
	}
	SceneBase::Update();

}

void PlayScene::Draw()
{
	SceneBase::Draw();

	switch (state) {
	case BEFORE_PLAY:
		DrawString(0, 20, "BEFORE_PLAY", GetColor(255, 255, 255));
		break;
	case IN_PLAY:
		DrawString(0, 20, "IN_PLAY", GetColor(255, 255, 255));
		break;
	case CLEAR:
		DrawString(0, 20, "CLEAR", GetColor(255, 255, 255));
		break;
	case GAMEOVER:
		DrawString(0, 20, "GAME_OVER", GetColor(255, 255, 255));
		break;
	}

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}

bool PlayScene::CanMove() const
{
	return state != BEFORE_PLAY;
}

void PlayScene::Clear()
{
}

void PlayScene::GameOver()
{
}
