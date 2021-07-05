#pragma once
#include "../Library/sceneBase.h"

class PlayScene : public SceneBase {
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

	bool CanMove() const;

	void Clear();

	void GameOver();

private:
	enum STATE {
		BEFORE_PLAY,
		IN_PLAY,
		CLEAR,
		GAMEOVER,
	};
	STATE state;
	int counter;
	int hImage;
	int bgmSound;

	static int mStartTime;      //測定開始時刻
	static int mCount;          //カウンタ
	static float mFps;          //fps
	static const int N = 60;	//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS
};