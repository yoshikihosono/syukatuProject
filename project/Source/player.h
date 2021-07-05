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
	void Move();			//移動
	void Shot();			//ショット
	void Resurrection();	//復活
	void Collision();		//当たり判定
	Vector2 GetPosition();
	int score;				//スコア
private:
	Vector2 position;			//プレイヤーの画像の座標
	Vector2 corePosition;		//プレイヤーの当たり判定の座標
	int hPlayerImage;			//自機の画像ファイルのハンドラ
	int hPlayerCoreImage;		//自機の当たり判定の画像ファイルのハンドラ
	float shotCoolTime;			//ショットのクールタイム
	bool exist;					//生きてたらtrue
	float resurrectionCoolTime;	//復活するまでの時間
	int invincibleTime;			//無敵時間
	int remainingPlayer;		//残機
	int shotPower;				//自機の攻撃力
	int bomb;					//ボムの数
	EnemyBase* e;
	EnemyManager* eM;
	EfectManager* efM;
	ItemManager* itM;

	enum State {
		INVICIBLE,	//無敵
		ALIVE,		//生きている
		DEAD,		//死んでいる
	};
	State state;
public:
	Vector2 pubPos;
};