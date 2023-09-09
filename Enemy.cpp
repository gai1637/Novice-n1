#include "Enemy.h"
#include"Novice.h"
#include"func.h"

Enemy::Enemy() {
	pos = { 1280,100 };
	tenbai = rand() % 2;
	size = 200;
	png = rand() % 5;
	switch (png)
	{
	case 0:
		png = Novice::LoadTexture("./Resouse/image/LADY.png");
		break;
	case 1:
		png = Novice::LoadTexture("./Resouse/image/OTAKU.png");
		break;
	case 2:
		png = Novice::LoadTexture("./Resouse/image/MAN.png");
		break;
	case 3:
		png = Novice::LoadTexture("./Resouse/image/BOY.png");
		break;
	case 4:
		png = Novice::LoadTexture("./Resouse/image/SHADY.png");
		break;
	}
	runflag=true;
	endflag=false;
}
void Enemy::Run() {
	if (runflag) {
		pos.x-=5;
	}
	if (pos.x <= 640 - (float)size / 2) {
		runflag = false;
	}
}
void Enemy::Draw() {
	if (runflag) {
		QE((int)pos.x, (int)pos.y, size,400, 200,200, 400, png);
	}
	else
	{
		Q((int)pos.x, (int)pos.y, size, 400, 200, 400, png);
	}
	
	
}
void Enemy::Que(bool flag,int num) {
	if (!flag) {
		switch (num)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			if (tenbai) {
			
			}
			else
			{

			}
			break;
		case 3:
			break;
		case 4:
			if (tenbai) {

			}
			else
			{

			}
			break;
		case 5:
			break;

		}
	}
}
void Enemy::Taiten(){	
	pos.x-=5;
}
void Enemy::TaitenDraw(bool f) {
	if (f) {
		QE((int)pos.x, (int)pos.y, size, 400, 200, 200, 400, png);
	}
	else {
		QE((int)pos.x, (int)pos.y, size, 400, 400, 200, 400, png);
	}
}