#include "efect.h"
#include <assert.h>

namespace {
	//定数の配列	テーブル
	static const std::string folder = "data\\texture\\efect\\";
	static const std::string fileName[Efect::hImage_ID::MAX] = {
		"efect1",
		"efect2",
		"efect3",
		"efect4",
		"efect5",
	};
}

Efect::Efect(SceneBase * scene, Vector2 _pos, int _pattern, int _drawPattern, float _valueSpeed, float _sizeSpeed, float firstSize,int _color) : GameObject(scene)
{
	position	= _pos;
	pattern		= _pattern;
	drawPattern = _drawPattern;
	valueSpeed	= _valueSpeed;
	sizeSpeed	= _sizeSpeed;
	size		= firstSize;
	color		= _color;
	value		= 255;
	efectKind	= 3;

	for (int i = 0; i < hImage_ID::MAX; i++) {
		hImage[i] = LoadGraph((folder + fileName[i] + ".png").c_str());
		assert(hImage[i] > 0);
	}

	for (int i = 0; i < 10; i++) {
		first[i] = true;
	}
}

Efect::~Efect()
{
}

void Efect::Update()
{
	switch (pattern) {
	case 0: pattern_0(); break;
	case 1: pattern_1(); break;
	case 2: pattern_2(); break;
	case 3: pattern_3(); break;
	}
}

void Efect::Draw()
{
	SetDrawArea(310, 30, 1175, 1040);
	
	switch (color) {
	case white:	SetDrawBright(255, 255, 255); break;
	case   red: SetDrawBright(255,	 0,	  0); break;
	case green: SetDrawBright(  0, 255,   0); break;
	case  blue: SetDrawBright(  0,   0, 255); break;
	}

	switch (drawPattern) {
	case 0: drawPattern_0(); break;
	case 1: drawPattern_1(); break;
	}
	SetDrawArea(0, 0, 1920, 1080);
	SetDrawBright(255, 255, 255);
}

void Efect::pattern_0()
{
	//生成場所を中心に大きくなって消える
	value -= valueSpeed;

	size += sizeSpeed;

	if (value <= 0)
		DestroyMe();
}

void Efect::pattern_1()
{
	//試作段階
	float angle[10];
	for (int i = 0; i < 10; i++) {
		if (first[i]) {
			pos[i] = position;
			first[i] = false;
		}
		angle[i] = (float)((360 / 10)* i * (DX_PI / 180));
		pos[i].x = pos[i].x + cos(angle[i]) * (i - 10);
		pos[i].y = pos[i].y + sin(angle[i]) * (10 - i);
	}

	value -= 3;

	if (value <= 0)
		DestroyMe();
}

void Efect::pattern_2()
{
	value -= valueSpeed;

	if (size < 5)
		size += sizeSpeed;

	if (size >= 5)
		size += sizeSpeed / 5;

	if (value <= 0)
		DestroyMe();
}

void Efect::pattern_3()
{
	value -= valueSpeed;

	size += sizeSpeed;

	position.y -= 5;
}

void Efect::drawPattern_0()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)value);
	DrawRotaGraph((int)position.x, (int)position.y, (int)size, 0, hImage[efectKind], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Efect::drawPattern_1()
{
	for (int i = 0; i < 10; i++) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)value);
		DrawRotaGraph(pos[i].x, pos[i].y, (int)size, 0, hImage[efectKind], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}
