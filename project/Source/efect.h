#pragma once
#include "..//Library/gameObject.h"
#include "vector2.h"

class Efect : public GameObject{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="scene"></param>
	/// <param name="pos">ê∂ê¨èÍèä</param>
	/// <param name="pattern"></param>
	/// <param name="drawPattern"></param>
	/// <param name="_valueSpeed"></param>
	/// <param name="_sizeSpeed"></param>
	/// <param name="firstSize"></param>
	/// <param name="_color"></param>
	Efect(SceneBase* scene, Vector2 pos, int pattern, int drawPattern, float _valueSpeed, float _sizeSpeed, float firstSize, int _color);
	~Efect();
	void Update();
	void Draw();
	void pattern_0();
	void pattern_1();
	void pattern_2();
	void pattern_3();
	void drawPattern_0();
	void drawPattern_1();
private:
	Vector2 position;
	Vector2 pos[10];
	int efectImage;
	float value;
	float valueSpeed;
	float size;
	float sizeSpeed;
	int pattern;
	int drawPattern;
	int efectKind;
	int color;
	bool first[10];

public:
	enum ColorPalette {
		white = 0,
		red,
		green,
		blue,
	};
	ColorPalette colorPalette;

	enum hImage_ID {
		efect1 = 0,
		efect2,
		efect3,
		efect4,
		efect5,
		MAX
	};
	int hImage[hImage_ID::MAX];
};