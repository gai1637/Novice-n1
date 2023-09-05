#include "GamePlay.h"
#include"Player.h"
#include<time.h>
#include"Novice.h"
#include"Enemy.h"
GamePlay::GamePlay() {
	
	player = new Player;
	count = 180;
	countNum = 3;
	for (int a = 0; a < 10; a++) {
		enemy[a] = new Enemy;
	}
	enemycount = 0;
	Numflag = true;
}
GamePlay::~GamePlay() {
	delete player;
	delete* enemy; 
		
	
	
}
void GamePlay::CountDawn() {
	if (count > 0) {
		count--;
		if (count % 60 == 0) {
			countNum--;
		}
	}
}
void GamePlay::Update() {
	CountDawn();
	if (count > -60) {
		count--;
	}
	if (count = -60) {
		Numflag = false;
	}
	if (count <= 0) {
		enemy[enemycount]->Run();
		if (!enemy[enemycount]->runflag) {

		}
	}
}