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
	int cnt;			//カウンタ
	float x, y;			//座標
	float speed;		//スピード
	float angle;		//角度
	int exist;			//生存フラグ
	int pattern;		//移動パターン
	int direction;		//向き
	int type;			//敵の種類
	int hp;				//体力
	int hp_max;			//体力最大値
	int itemKind;		//落とすアイテム
	int barrageTime;	//弾幕開始時間
	int maxBullet;		//弾の数
	int barrageKind;	//弾幕の種類
	int bulletKind;		//弾の種類
	int color;			//弾の色
	int state;			//敵の状態
	int waitTime;		//待機時間
	int stagnationTime;	//停滞時間

	EnemyManager* eM = GetScene()->FindGameObject<EnemyManager>();

	fp = FileRead_open(fname);	//ファイル読み込み
	if (fp == NULL) {
		printfDx("read error\n");
		return;
	}
	for (i = 0; i < 2; i++)	//最初の2行は読まない
		while (FileRead_getc(fp) != '\n');

	n = 0, num = 0;
	while (1) {
		for (i = 0; i < 64; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);	//1文字取得する
			if (inputc[i] == '/') {	//スラッシュがあったら
				while (FileRead_getc(fp) != '\n');	//改行までループ
				i = 1;	//カウンタを最初に戻して
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {	//カンマか改行なら
				inputc[i] = '\0';	//そこまでを文字列とし
				break;
			}
			if (input[i] == EOF) {
				goto EXFILE;	//終了
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
