#include "Enemy.h"
#include"Novice.h"
#include"func.h"
Enemy::Enemy() {
	pos = { 1280,0 };
	tenbai = rand() % 2;
	size = 1;
	png = 0;
	runflag=true;
	endflag=false;
}
void Enemy::Run() {
	if (runflag) {
		pos.x--;
	}
	if (pos.x <= 640 - (float)size / 2) {
		runflag = false;
	}
}
void Enemy::Draw() {
	Q((int)pos.x, (int)pos.y, size, size, 200, 400, png);
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