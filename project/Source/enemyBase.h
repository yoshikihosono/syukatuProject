#pragma once
#include "../Library/gameObject.h"
#include "vector2.h"
#include "efectManager.h"

/// <summary>
/// �G�̊��N���X
/// </summary>
class EnemyBase : public GameObject {
public:
	EnemyBase(SceneBase* _scene) : GameObject(_scene) {}
	virtual ~EnemyBase() {}
	virtual void Update() override {}
	virtual void Draw() override {}
	virtual bool Collision(Vector2 center, float radius) const { return false; }	//�v���C���[�A�e�Ƃ̓����蔻��
	virtual void AddDamage(int damage){}	
	virtual void MovePattern_0(){}	//�ړ��p�^�[��
	virtual void MovePattern_1(){}	//�ړ��p�^�[��
	virtual void MovePattern_2(){}	//�ړ��p�^�[��
	virtual void MovePattern_3(){}	//�ړ��p�^�[��
	virtual void MovePattern_4(){}	//�ړ��p�^�[��
	virtual void MovePattern_5(){}	//�ړ��p�^�[��
	virtual Vector2 GetPosition() { return position; }
private:
	Vector2 position;	//���W
	Vector2 velocity;	//���x����
	float spped;		//�X�s�[�h
	float angle;		//�p�x
	int cnt;			//�J�E���^
	int exist;			//�����t���O
	int pattern;		//�ړ��p�^�[��
	int direction;		//����
	int type;			//�G�̎��
	int hp;				//�̗�
	int hp_max;			//�̗͍ő�l
	int item[6];		//���Ƃ��A�C�e��
	int barrageTime;	//�e���J�n����
	int barrageKind;	//�e���̎��
	int bulletKind;		//�e�̎��
	int color;			//�e�̐F
	int state;			//�G�̏��
	int waitTime;		//�ҋ@����
	int stagnationTime;	//��؎���
};