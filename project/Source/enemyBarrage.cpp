#include "enemyBarrage.h"
#include <assert.h>

namespace {
	//定数の配列	テーブル
	static const std::string folder = "data\\texture\\enemybullet\\";
	static const std::string fileName[EnemyBarrage::hImage_ID::MAX] = {
		"dotbullet",
		"smallbullet1",
		"smallbullet2",
		"mediumbullet",
		"largebullet",
		"ricegrainbullet2"
	};
}

EnemyBarrage::EnemyBarrage(SceneBase* _scene, Vector2 _pos, double _base_angle,int _bulletMax, Vector2 _playerPos, int _bulletKind, int _bulletColor, float _speed) : GameObject(_scene)
{
	bulletMax = _bulletMax;
	//pattern = 0;
	bulletKind = _bulletKind;
	bulletColor = _bulletColor;
	plPos = _playerPos;

	/*for (int i = 0; i < bulletMax; i++) {
		bullet[i].position = _pos;
		bullet->flag = true;
		bullet[i].first = true;
		bullet->spd = _speed;
	}*/

	position = _pos;
	flag = true;
	spd = _speed;
	base_angle = _base_angle;

	for (int i = 0; i < hImage_ID::MAX; i++) {
		hImage[i] = LoadGraph((folder + fileName[i] + ".png").c_str());
		assert(hImage[i] > 0);
	}


	switch (bulletKind) {
	case		dotbullet:	WIDTH = 9;	HEIGHT = 9; CENTER_X = 4; CENTER_Y = 4; RADIUS = 4; break;
	case	 smallbullet1:	WIDTH = 13; HEIGHT = 13; CENTER_X = 6; CENTER_Y = 6; RADIUS = 6; break;
	case	 smallbullet2:	WIDTH = 17; HEIGHT = 17; CENTER_X = 8; CENTER_Y = 8; RADIUS = 8; break;
	case	 mediumbullet:	WIDTH = 27; HEIGHT = 27; CENTER_X = 13; CENTER_Y = 13; RADIUS = 13; break;
	case	  largebullet:	WIDTH = 62; HEIGHT = 62; CENTER_X = 31; CENTER_Y = 31; RADIUS = 22; break;
	case  ricegrainbullet:	WIDTH = 16; HEIGHT = 7; CENTER_X = 8; CENTER_Y = 3; RADIUS = 3; break;
	}

	coolTime = 0;
}

EnemyBarrage::~EnemyBarrage()
{
}

void EnemyBarrage::Update()
{
	/*for (int i = 0; i < bulletMax; i++) {
		bullet[i].cnt += 1;
		bullet[i].position.x = bullet[i].position.x + cos(bullet[i].angle) * bullet[i].spd;
		bullet[i].position.y = bullet[i].position.y + sin(bullet[i].angle) * bullet[i].spd;
	}*/

	cnt += 1;
	position.x = position.x + cos(angle) * spd;
	position.y = position.y + sin(angle) * spd;

	/*画面外に出たら消す*/
	/*for (int i = 0; i < bulletMax; i++) {
		if (bullet[i].position.x + WIDTH < 310 || bullet[i].position.x > 1175 || bullet[i].position.y + HEIGHT < -40 || bullet[i].position.y > 1040) {
			bullet[i].flag = false;
		}
	}*/

	if (position.x + WIDTH < 310 || position.x > 1175 || position.y + HEIGHT < -40 || position.y > 1040) {
		flag = false;
	}
	/*画面外に出たら消す*/

	cnt += 1;
	coolTime -= 1;
}

void EnemyBarrage::Draw()
{
	switch (bulletColor) {
	case white:	SetDrawBright(255, 255, 255); break;
	case   red: SetDrawBright(255, 0, 0); break;
	case green: SetDrawBright(0, 255, 0); break;
	case  blue: SetDrawBright(0, 0, 255); break;
	}

	//for (int i = 0; i < bulletMax; i++) {
	//	if (bullet[i].flag) {
	//		//DrawGraph((int)bullet[i].position.x, (int)bullet[i].position.y, hImage[bulletKind], true);
	//		DrawRotaGraph((int)bullet[i].position.x, (int)bullet[i].position.y, 1, bullet[i].angle, hImage[bulletKind], true);
	//	}
	//}

	if (flag) {
		DrawRotaGraph((int)position.x, (int)position.y, 1, base_angle, hImage[bulletKind],true);
	}
	SetDrawBright(255, 255, 255);
}

//void EnemyBarrage::BarragePattern_0(int _i)
//{
//	/*拡散弾*/
//	bullet[_i].angle = (float)((360 / bulletMax) * _i * (DX_PI / 180));
//	//bullet[_i].position.x = bullet[_i].position.x + cos(bullet[_i].angle) * 5;
//	//bullet[_i].position.y = bullet[_i].position.y + sin(bullet[_i].angle) * 5;
//	bullet[_i].spd = 5;
//	bullet[_i].flag = true;
//
//	coolTime = 300;
//
//	for (int i = 0; i < bulletMax; i++) {
//		if (!bullet[i].flag) {
//			bullet[i].angle = (float)((360))
//		}
//	}
//}
//
//void EnemyBarrage::BarragePattern_1(int _i)
//{
//	/*自機狙い*/
//	if (bullet[_i].first) {
//		bullet[_i].angle = Shotatan2(bullet[_i].position);
//		bullet[_i].first = false;
//	}
//	bullet[_i].position.x = bullet[_i].position.x + cos(bullet[_i].angle) * (_i + 1);
//	bullet[_i].position.y = bullet[_i].position.y + sin(bullet[_i].angle) * (_i + 1);
//	bullet[_i].flag = true;
//}
//
//void EnemyBarrage::BarragePattern_2(int _i)
//{
//	//ばらまき
//	int t = bullet[_i].cnt;
//	if (t >= 0 && t < 120 && t % 2 == 0) {
//		if (bullet[_i].first) {
//			bullet[_i].angle = Shotatan2(bullet[_i].position) + Rang(PI / 4);
//			bullet[_i].first = false;
//		}
//		bullet[_i].flag = 1;
//		bullet[_i].cnt = 0;
//		bullet[_i].spd = 3 + Rang(1.5);
//	}
//}
//
//void EnemyBarrage::BarragePattern_3(int _i)
//{
//	//ばらまき(減速)
//	int t = bullet[_i].cnt;
//	if (t >= 0 && t < 120 && t % 2 == 0) {
//		if (bullet[_i].first) {
//			bullet[_i].angle = Shotatan2(bullet[_i].position) + Rang(PI / 4);
//			bullet[_i].first = false;
//		}
//		bullet[_i].flag = 1;
//		bullet[_i].cnt = 0;
//		bullet[_i].spd = 4 + Rang(2);
//	}
//	for (int i = 0; i < bulletMax; i++) {//全弾分ループ
//		if (bullet[i].spd > 1.5)//速度が1.5より大きいものがあれば
//			bullet[i].spd -= 0.04;//減速
//	}
//}
//
//void EnemyBarrage::BarragePattern_4(int _i)
//{
//	int t = cnt;
//	if (t >= 0 && t < 1200 && t % 90 == 0) {
//		double angle = rang(PI, bullet[_i].angle);
//		for (int j = 0; j < 2; j++) {//途中から２分裂する分
//			bullet[_i].angle = angle + PI2 / 60 * _i;//円形60個
//			bullet[_i].flag = true;
//			bullet[_i].cnt = 0;
//			bullet[_i].state = j;//ステータス。0か1かで回転がかわる
//			bullet[_i].spd = 2;
//		}
//	}
//	if (bullet[_i].flag > 0) {//登録されている弾があれば
//		int state = bullet[_i].state;
//		int cnt = bullet[_i].cnt;
//		if (30 < cnt && cnt < 120) {//30～120カウントなら
//			bullet[_i].spd -= 1.2 / 90.0;//90カウントかけて1.2減らす
//			bullet[_i].angle += (PI / 2) / 90.0*(state ? -1 : 1);//90カウントかけて90°傾ける
//		}
//	}
//}

bool EnemyBarrage::Collision(Vector2 center, float radius) const
{
	/*for (int i = 0; i < bulletMax; i++) {
		float dx = (bullet[i].position.x + CENTER_X) - center.x;
		float dy = (bullet[i].position.y + CENTER_Y) - center.y;
		if (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS)) {
			return true;
			break;
		}
	}*/

	float dx = (position.x + CENTER_X) - center.x;
	float dy = (position.y + CENTER_Y) - center.y;
	if (dx*dx + dy * dy < (radius + RADIUS)*(radius + RADIUS)) {
		return true;
	}

	return false;
}
