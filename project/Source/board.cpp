#include "board.h"
#include <assert.h>

Board::Board(SceneBase* _scene) : GameObject (_scene)
{
	hImage = LoadGraph("data\\texture\\board.png");
	assert(hImage > 0);
}

Board::~Board()
{
}

void Board::Update()
{
}

void Board::Draw()
{
	DrawGraph(240, 0, hImage, true);
}
