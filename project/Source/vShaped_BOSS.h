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
	Vector2 velocity;	//速度成分
	int cnt;			//カウンタ
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
	bool shotFlag;		//弾を撃っていたらtrue

	Vector2 plPos;	//自機の座標

	EnemyBarrageManager* eBM;
	EfectManager* efM;
	ItemManager* itM;
	EnemyShotManager* eSM;
	Player* pl;
};