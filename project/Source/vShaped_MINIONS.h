#pragma once
#include "enemyBase.h"
#include "enemyBarrageManager.h"
#include "itemManager.h"
#include "enemyShotManager.h"
#include "player.h"
#include "vShaped_BOSS.h"

class VShaped_MINIONS : public EnemyBase {
public:
	VShaped_MINIONS(SceneBase* scene, int x, int y, int cnt, int pattern,
		float speed, int barrageTime, int maxBullet, int barrageKind, int color,
		int hp, int bulletKind, int waitTime, int stagnationTime, int itemKind, EnemyBase* _boss);
	~VShaped_MINIONS();
	void Update() override;
	void Draw() override;
	bool Collision(Vector2 center, float radius) const override;
	void AddDamage(int damage) override;
	void setBoss(EnemyBase* _e);
	double HomingBoss(Vector2 _bPos);
private:
	int hImage;
	bool hitShot;
	Vector2 position;	//自分の座標
	Vector2 bPosition;	//親分の現在座標
	Vector2 beforeBossPos;
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
	bool specialAttack;	//trueだったら特攻
	double base_angle;

	Vector2 plPos;	//自機の座標

	EnemyManager* eM;
	EnemyBarrageManager* eBM;
	EfectManager* efM;
	ItemManager* itM;
	EnemyShotManager* eSM;
	Player* pl;
	EnemyBase* boss;
};