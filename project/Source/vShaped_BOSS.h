#pragma once
#include "enemyBase.h"
#include "enemyBarrageManager.h"
#include "itemManager.h"
#include "enemyShotManager.h"
#include "player.h"

class VShaped_BOSS : public EnemyBase {
public:
	VShaped_BOSS(SceneBase* scene, int x, int y, int cnt, int pattern,
		float speed, int barrageTime, int maxBullet, int barrageKind, int color,
		int hp, int bulletKind, int waitTime, int stagnationTime, int itemKind);
	~VShaped_BOSS();
	void Update() override;
	void Draw() override;
	bool Collision(Vector2 center, float radius) const override;
	void AddDamage(int damage) override;
	void MovePattern_0() override;
	Vector2 GetPosition();
private:
	int hImage;
	bool hitShot;
	Vector2 position;
	Vector2 velocity;	//���x����
	int cnt;			//�J�E���^
	float speed;		//�X�s�[�h
	float angle;		//�p�x
	int exist;			//�����t���O
	int pattern;		//�ړ��p�^�[��
	int direction;		//����
	int type;			//�G�̎��
	int hp;				//�̗�
	int hp_max;			//�̗͍ő�l
	int itemKind;		//���Ƃ��A�C�e��
	int barrageTime;	//�e���J�n����
	int maxBullet;		//�e�̐�
	int barrageKind;	//�e���̎��
	int bulletKind;		//�e�̎��
	int color;			//�e�̐F
	int state;			//�G�̏��
	int waitTime;		//�ҋ@����
	int stagnationTime;	//��؎���
	bool shotFlag;		//�e�������Ă�����true

	Vector2 plPos;	//���@�̍��W

	EnemyBarrageManager* eBM;
	EfectManager* efM;
	ItemManager* itM;
	EnemyShotManager* eSM;
	Player* pl;
};