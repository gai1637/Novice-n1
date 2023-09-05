#include "Enemy.h"
#include"Novice.h"
#include"func.h"
Enemy::Enemy() {
	pos = { 1280,0 };
	tenbai = rand() % 2;
	size = 1;
	png = 0;
}
void Enemy::Run() {
	if (pos.x > 640 - (float)size / 2) {
		pos.x--;
	}
}
void Enemy::Draw() {
	Q((int)pos.x, (int)pos.y, size, size, 200, 400, png);
}