#include "player.h"
#include <assert.h>

#include "debugScreen.h"

namespace {
	static const int	playerHeight = 48;		//高さ
	static const int	playerWidth = 48;		//幅
	static const int	playerRadius = 24;
	static const float	moveSpeed = 10.0f;	//移動速度
}

Player::Player(SceneBase* scene) : GameObject(scene)
{
	position = Vector2(725, 900);
	corePosition = Vector2(position.x + 15, position.y + 21);
	shotCoolTime = 0;
	remainingPlayer = 3;
	shotPower = 9;
	hPlayerImage = LoadGraph("data\\texture\\reimu.png");
	assert(hPlayerImage > 0);
	hPlayerCoreImage = LoadGraph("data\\texture\\playercore.png");
	assert(hPlayerCoreImage > 0);
	pubPos = position;
	exist = true;
	efM = GetScene()->FindGameObject<EfectManager>();
	eM = GetScene()->FindGameObject<EnemyManager>();
	itM = GetScene()->FindGameObject<ItemManager>();
	state = INVICIBLE;
	invincibleTime = 150;
	score = 0;
}

Player::~Player()
{
	DestroyMe();
}

void Player::Update()
{
	if (shotPower <= 0)
		shotPower = 1;

	switch (state)
	{
	case INVICIBLE:

		Move();
		Shot();
		Collision();
		invincibleTime -= 1;
		pubPos = position;
		corePosition = Vector2(position.x + 15.0f, position.y + 21.0f);

		if (invincibleTime <= 0) {
			state = ALIVE;
		}

		break;
	case ALIVE:

		Move();
		Shot();
		Collision();
		corePosition = Vector2(position.x + 15.0f, position.y + 21.0f);

		shotCoolTime--;

		pubPos = position;
		corePosition = Vector2(position.x + 15.0f, position.y + 21.0f);

		break;
	case DEAD:

		Resurrection();

		break;
	default:
		break;
	}
}

void Player::Draw()
{
	switch (state)
	{
	case INVICIBLE:

		if (invincibleTime % 2 == 0) {
			SetDrawBright(40, 40, 40);
			DrawGraph((int)position.x, (int)position.y, hPlayerImage, true);	//プレイヤーの描画
			DrawGraph((int)position.x + 15, (int)position.y + 21, hPlayerCoreImage, true);	//プレイヤーの描画
			SetDrawBright(255, 255, 255);
		}

		if (invincibleTime % 2 == 1) {
			DrawGraph((int)position.x, (int)position.y, hPlayerImage, true);	//プレイヤーの描画
			DrawGraph((int)position.x + 15, (int)position.y + 21, hPlayerCoreImage, true);	//プレイヤーの描画
		}


		DebugPrintf(0, 200, "STATE = INVICIBLE");
		break;
	case ALIVE:

		DrawGraph((int)position.x, (int)position.y, hPlayerImage, true);	//プレイヤーの描画
		DrawGraph((int)position.x + 15, (int)position.y + 21, hPlayerCoreImage, true);	//プレイヤーの描画
		DebugPrintf(0, 200, "STATE = ALIVE");

		break;
	case DEAD:

		DebugPrintf(0, 200, "STATE = DEAD");

		break;
	default:
		break;
	}
	int posX, posY;
	posX = position.x;
	posY = position.y;
	int cposX, cposY;
	cposX = corePosition.x + 5;
	cposY = corePosition.y + 5;
	DebugPrintf(0, 480, "score:%d", score);
	DebugPrintf(0, 500, "あと%d", remainingPlayer);
	DebugPrintf(0, 520, "Power:%d", shotPower);
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		position.x -= moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		position.x += moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		position.y -= moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		position.y += moveSpeed;
	}

	if (position.x < 310)
	{
		position.x = 310;
	}

	if (position.x + playerWidth > 1175)
	{
		position.x = 1175.0f - playerWidth;
	}

	if (position.y < 30)
	{
		position.y = 30;
	}

	if (position.y + playerHeight > 1040)
	{
		position.y = 1040.0f - playerHeight;
	}
}

void Player::Shot()
{
	ShotManager* s = GetScene()->FindGameObject<ShotManager>();

	if (CheckHitKey(KEY_INPUT_Z))
	{
		if (shotCoolTime < 0) {
			if (shotPower < 10) {
				s->Spawn(position);
			}
			if (shotPower >= 10 && shotPower < 20) {
				s->Spawn(Vector2(position.x - 15, position.y));
				s->Spawn(Vector2(position.x + 15, position.y));
			}
			if (shotPower >= 20 && shotPower < 30) {
				s->Spawn(position);
				s->Spawn(Vector2(position.x - 30, position.y));
				s->Spawn(Vector2(position.x + 30, position.y));
			}
			if (shotPower >= 30 && shotPower < 40) {
				s->Spawn(Vector2(position.x - 15, position.y));
				s->Spawn(Vector2(position.x - 45, position.y));
				s->Spawn(Vector2(position.x + 15, position.y));
				s->Spawn(Vector2(position.x + 45, position.y));
			}
			if (shotPower >= 40) {
				s->Spawn(position);
				s->Spawn(Vector2(position.x - 30, position.y));
				s->Spawn(Vector2(position.x - 60, position.y));
				s->Spawn(Vector2(position.x + 30, position.y));
				s->Spawn(Vector2(position.x + 60, position.y));
			}
			shotCoolTime = 5;
		}
	}
	shotCoolTime--;
}

void Player::Resurrection()
{
	if (remainingPlayer >= 0) {
		if (resurrectionCoolTime <= 0) {
			position = Vector2(Vector2(725, 900));
			exist = true;
			state = INVICIBLE;
			invincibleTime = 180;
		}
	}
	resurrectionCoolTime -= 1;
}

void Player::Collision()
{
	if (state == ALIVE) {
		e = eM->Collision(Vector2(corePosition.x + 5.0f, corePosition.y + 5.0f), 5.0f);
		EnemyBarrageManager* eBM = GetScene()->FindGameObject<EnemyBarrageManager>();
		eBM->GetPlayerPosition(Vector2(corePosition.x + 5.0f, corePosition.y + 5.0f));

		if (e != nullptr) {
			efM->Create(position, 0, 0, 3, 1, 2, Efect::ColorPalette::white);
			remainingPlayer -= 1;
			resurrectionCoolTime = 60;
			shotPower -= 5;
			exist = false;
			state = DEAD;
		}

		if (eBM->Collision(Vector2(corePosition.x + 5.0f, corePosition.y + 5.0f), 5.0f)) {
			efM->Create(position, 0, 0, 3, 1, 2, Efect::ColorPalette::white);
			remainingPlayer -= 1;
			resurrectionCoolTime = 60;
			shotPower -= 5;
			exist = false;
			state = DEAD;
		}
	}

	int ItemKind = 0;
	ItemKind = itM->Collision(Vector2(corePosition.x + 5.0f, corePosition.y + 5.0f), playerRadius);

	switch (ItemKind)
	{
	case 1: shotPower += 1;		  break;
	case 2: score += 1000;		  break;
	case 3: bomb += 1;			  break;
	case 4: remainingPlayer += 1; break;
	}
}

Vector2 Player::GetPosition()
{
	return position;
}
