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
	/// <param name="pos">�����ꏊ</param>
	/// <param name="_pattern">�����̃p�^�[��</param>
	/// <param name="_drawPattern">�`��p�^�[��</param>
	/// <param name="_valueSpeed">�����鑬�x</param>
	/// <param name="_sizeSpeed">�T�C�Y�̕ς�鑬�x</param>
	/// <param name="firstSize">�ŏ��̑傫��</param>
	void Create(Vector2 pos, int _pattern, int _drawPattern, float _valueSpeed, float _sizeSpeed, float firstSize, int _color);
private:
	std::list<Efect*> efects;
};