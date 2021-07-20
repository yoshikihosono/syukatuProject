#pragma once
#include "../Library/gameObject.h"
#include "vector2.h"
#include "efectManager.h"

/// <summary>
/// 敵の基底クラス
/// </summary>
class EnemyBase : public GameObject {
public:
	EnemyBase(SceneBase* _scene) : GameObject(_scene) {}
	virtual ~EnemyBase() {}
	virtual void Update() override {}
	virtual void Draw() override {}
	virtual bool Collision(Vector2 center, float radius) const { return false; }	//プレイヤー、弾との当たり判定
	virtual void AddDamage(int damage){}	
	virtual void MovePattern_0(){}	//移動パターン
	virtual void MovePattern_1(){}	//移動パターン
	virtual void MovePattern_2(){}	//移動パターン
	virtual void MovePattern_3(){}	//移動パターン
	virtual void MovePattern_4(){}	//移動パターン
	virtual void MovePattern_5(){}	//移動パターン
	virtual Vector2 GetPosition() { return position; }
private:
	Vector2 position;	//座標
	Vector2 velocity;	//速度成分
	float spped;		//スピード
	float angle;		//角度
	int cnt;			//カウンタ
	int exist;			//生存フラグ
	int pattern;		//移動パターン
	int direction;		//向き
	int type;			//敵の種類
	int hp;				//体力
	int hp_max;			//体力最大値
	int item[6];		//落とすアイテム
	int barrageTime;	//弾幕開始時間
	int barrageKind;	//弾幕の種類
	int bulletKind;		//弾の種類
	int color;			//弾の色
	int state;			//敵の状態
	int waitTime;		//待機時間
	int stagnationTime;	//停滞時間
};