#pragma once
#include "vector2.h"

typedef struct {
	int flag;			//�t���O
	int cnt;			//�J�E���^
	int power;			//�p���[
	int point;			//�|�C���g
	int score;			//�X�R�A
	int num;			//�c�@��
	int mutekicnt;		//���G��ԂƃJ�E���g
	int shot_mode;		//�V���b�g���[�h
	int money;			//����
	int img;			//�摜
	int slow;			//�X���[���ǂ���
	Vector2 position;	//���W
}ch_t;

typedef struct {
	//�t���O�A�J�E���^�A�ړ��p�^�[���A�����A�G�̎�ށAHP�ő�l�A���Ƃ��A�C�e���A�摜
	int flag;
	int cnt;
	int pattern;
	int muki;
	int knd;
	int hp;
	int hp_max;
	int item_n[6];
	int img;
	//���W�A���xx�����A���xy�����A�X�s�[�h�A�p�x
	double x, y, vx, vy, sp, ang;
	//�e���J�n���ԁA�e���̎�ށA�e�̎�ށA�F�A��ԁA�ҋ@���ԁA��؎���
	int bltime, blknd, blknd2, col, state, wtime, wait;
}enemy_t;