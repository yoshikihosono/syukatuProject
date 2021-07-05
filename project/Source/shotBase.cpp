#include "shotBase.h"
#include "enemyManager.h"
#include "enemyBase.h"
#include "efectManager.h"

ShotBase::ShotBase(SceneBase * _scene, Vector2 _pos) : GameObject(_scene)
{
	position.x = _pos.x;
	position.y = _pos.y;
	hImage = LoadGraph("data\\texture\\shot.png");
	value = 255;
	size = 0;
}

ShotBase::~ShotBase()
{
}

void ShotBase::Update()
{
	position.y -= speed;

	EfectManager* efM = GetScene()->FindGameObject<EfectManager>();

	if (position.y < 30) {
		DestroyMe();
	}

	EnemyManager* eneM = GetScene()->FindGameObject<EnemyManager>();
	EnemyBase* e = eneM->Collision(Vector2(position.x + 10.0f, position.y + 10.0f), 5.0f);
	if (e != nullptr) {
		efM->Create(position, 3, 0, 5, 0.1f, 1, Efect::ColorPalette::red);
		e->AddDamage(10);
		DestroyMe();
	}
}

void ShotBase::Draw()
{
	DrawGraph((int)position.x + 10, (int)position.y, hImage, true);
}
