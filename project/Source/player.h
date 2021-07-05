#pragma once
#include "../Library/gameObject.h"
#include "shotManager.h"
#include "vector2.h"
#include "efectManager.h"
#include "enemyBase.h"
#include "enemyManager.h"
#include "enemyBarrageManager.h"
#include "enemyBarrageManager.h"
#include "itemManager.h"

class Player : public GameObject 
{
public:
	Player(SceneBase* scene);
	~Player();
	void Update();
	void Draw();
	void Move();			//�ړ�
	void Shot();			//�V���b�g
	void Resurrection();	//����
	void Collision();		//�����蔻��
	Vector2 GetPosition();
	int score;				//�X�R�A
private:
	Vector2 position;			//�v���C���[�̉摜�̍��W
	Vector2 corePosition;		//�v���C���[�̓����蔻��̍��W
	int hPlayerImage;			//���@�̉摜�t�@�C���̃n���h��
	int hPlayerCoreImage;		//���@�̓����蔻��̉摜�t�@�C���̃n���h��
	float shotCoolTime;			//�V���b�g�̃N�[���^�C��
	bool exist;					//�����Ă���true
	float resurrectionCoolTime;	//��������܂ł̎���
	int invincibleTime;			//���G����
	int remainingPlayer;		//�c�@
	int shotPower;				//���@�̍U����
	int bomb;					//�{���̐�
	EnemyBase* e;
	EnemyManager* eM;
	EfectManager* efM;
	ItemManager* itM;

	enum State {
		INVICIBLE,	//���G
		ALIVE,		//�����Ă���
		DEAD,		//����ł���
	};
	State state;
public:
	Vector2 pubPos;
};