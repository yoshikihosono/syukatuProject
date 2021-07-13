#include "field.h"
#include "enemyManager.h"

Field::Field(SceneBase * scene) : GameObject(scene)
{

}

Field::~Field()
{
}

void Field::Start()
{
	int n, num, i, fp;
	char fname[32] = { "data\\enemy\\storyH0.csv" };
	int input[64];
	char inputc[64];
	int cnt;			//�J�E���^
	float x, y;			//���W
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

	EnemyManager* eM = GetScene()->FindGameObject<EnemyManager>();

	fp = FileRead_open(fname);	//�t�@�C���ǂݍ���
	if (fp == NULL) {
		printfDx("read error\n");
		return;
	}
	for (i = 0; i < 2; i++)	//�ŏ���2�s�͓ǂ܂Ȃ�
		while (FileRead_getc(fp) != '\n');

	n = 0, num = 0;
	while (1) {
		for (i = 0; i < 64; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);	//1�����擾����
			if (inputc[i] == '/') {	//�X���b�V������������
				while (FileRead_getc(fp) != '\n');	//���s�܂Ń��[�v
				i = 1;	//�J�E���^���ŏ��ɖ߂���
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {	//�J���}�����s�Ȃ�
				inputc[i] = '\0';	//�����܂ł𕶎���Ƃ�
				break;
			}
			if (input[i] == EOF) {
				goto EXFILE;	//�I��
			}
		}
		switch (num) {
		case 0: cnt				= atoi(inputc); break;
		case 1: pattern			= atoi(inputc); break;
		case 2: type			= atoi(inputc);	break;
		case 3:	x				= atoi(inputc);	break;
		case 4: y				= atoi(inputc); break;
		case 5: speed			= atoi(inputc); break;
		case 6: barrageTime		= atoi(inputc); break;
		case 7: maxBullet		= atoi(inputc); break;
		case 8: barrageKind		= atoi(inputc); break;
		case 9: color			= atoi(inputc); break;
		case 10: hp				= atoi(inputc); break;
		case 11:bulletKind		= atoi(inputc); break;
		case 12:waitTime		= atoi(inputc); break;
		case 13:stagnationTime	= atoi(inputc); break;
		case 14:itemKind		= atoi(inputc); break;
		}
		num++;
		if (num == 15) {
			switch (type) {
			case 0: eM->Create(EnemyManager::ENEMY_TYPE::FURBALL, x, y, cnt, pattern, speed, barrageTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind); break;
			case 1: eM->Create(EnemyManager::ENEMY_TYPE::FAIRY, x, y, cnt, pattern, speed, barrageTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind); break;
			case 2: eM->Create(EnemyManager::ENEMY_TYPE::VSHAPED, x, y, cnt, pattern, speed, barrageTime, maxBullet, barrageKind, color, hp, bulletKind, waitTime, stagnationTime, itemKind); break;
			}
			num = 0;
			n++;
		}

	}

EXFILE:
	FileRead_close(fp);
}

void Field::Draw()
{
}
