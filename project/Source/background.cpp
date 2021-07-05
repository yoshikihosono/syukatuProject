#include "background.h"
#include <assert.h>

BackGround::BackGround(SceneBase * scene) : GameObject(scene)
{
	hImage = LoadGraph("data\\texture\\haikei.png");
	assert(hImage > 0);
	firstY = 30;
	secondY = -980;
}

BackGround::~BackGround()
{
}

void BackGround::Update()
{
	firstY += 5;
	secondY += 5;

	if (firstY > 1040) {
		firstY = -975;
	}
	if (secondY > 1040) {
		secondY = -975;
	}
}

void BackGround::Draw()
{
	DrawGraph(X, firstY, hImage, true);
	DrawGraph(X, secondY, hImage, true);
	DrawBox(310, 30, 1175, 1040, GetColor(255, 255, 255), false);	//プレイ領域
	DrawLine(310, 535, 1175, 535, GetColor(255, 255, 255));	//プレイ領域の真ん中の線
	DrawLine(240, 0, 240, 1080, GetColor(255, 255, 255));	//左端の線
	DrawLine(1680, 0, 1680, 1080, GetColor(255, 255, 255));	//右端の線
	DrawLine(742.5f, 30, 742.5f, 1040, GetColor(255, 255, 255));	//右端の線
}
