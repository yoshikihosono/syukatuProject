#pragma once
//efectManager.h
#include "..//Library/gameObject.h"
#include "efect.h"

class EfectManager : public GameObject {
public:
	EfectManager(SceneBase* scene);
	~EfectManager();
	void Update();
	void Draw();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="pos">生成場所</param>
	/// <param name="_pattern">動きのパターン</param>
	/// <param name="_drawPattern">描画パターン</param>
	/// <param name="_valueSpeed">消える速度</param>
	/// <param name="_sizeSpeed">サイズの変わる速度</param>
	/// <param name="firstSize">最初の大きさ</param>
	void Create(Vector2 pos, int _pattern, int _drawPattern, float _valueSpeed, float _sizeSpeed, float firstSize, int _color);
private:
	std::list<Efect*> efects;
};