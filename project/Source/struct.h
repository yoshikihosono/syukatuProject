#pragma once
#include "vector2.h"

typedef struct {
	int flag;			//フラグ
	int cnt;			//カウンタ
	int power;			//パワー
	int point;			//ポイント
	int score;			//スコア
	int num;			//残機数
	int mutekicnt;		//無敵状態とカウント
	int shot_mode;		//ショットモード
	int money;			//お金
	int img;			//画像
	int slow;			//スローかどうか
	Vector2 position;	//座標
}ch_t;

typedef struct {
	//フラグ、カウンタ、移動パターン、向き、敵の種類、HP最大値、落とすアイテム、画像
	int flag;
	int cnt;
	int pattern;
	int muki;
	int knd;
	int hp;
	int hp_max;
	int item_n[6];
	int img;
	//座標、速度x成分、速度y成分、スピード、角度
	double x, y, vx, vy, sp, ang;
	//弾幕開始時間、弾幕の種類、弾の種類、色、状態、待機時間、停滞時間
	int bltime, blknd, blknd2, col, state, wtime, wait;
}enemy_t;