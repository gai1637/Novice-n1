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
	situmon = false;
	F = true;
	ketudan = false;
	kekka = false;
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
			if (F) {
				situmon = true;
				F = false;
			}
			if (!situmon) {
				situmoncount++;
				if (situmoncount >= 120) {
					situmon = true;
				}
			}
			if (Novice::IsTriggerMouse) {
				if (sit <= 2) {
					if (player->posy > 510 && player->posy < 710) {
						if (player->posx > 20
							&& player->posx < 420) {
							situmonNum = 0;
							if (sit = 1) {
								situmonNum = 3;
							}
							situmon = false;
							sit++;
						}else if (player->posx > 440&& player->posx > 840) {
							situmonNum = 1;
							if (sit = 1) {
								situmonNum = 4;
							}
							situmon = false;
							sit++;
						}else if (player->posx > 860&& player->posx < 1260) {
							situmonNum = 2;
							if (sit = 1) {
								situmonNum = 5;
							}
							situmon = false;
							sit++;
						}
						
					}
				}
				else
				{
					if (player->posy > 510 && player->posy < 710) {
						if (player->posx >= 120
							&& player->posx <= 520) {
							kekka = true;
							ketudan = true;
						}
						if (player->posx >= 760
							&& player->posx <= 1160) {
							kekka = false;
							ketudan = true;
						}
					}
					if (ketudan) {
						enemy[enemycount]->Taiten();
						if (enemy[enemycount]->pos.x <= -enemy[enemycount]->size) {
							F = true;
							situmon = false;
							sit = 0;
							ketudan = false;
							enemycount++;
						}
					}
				}
				
			}
			
			
		}
	}
	
}
void GamePlay::Draw() {

	if (!F) {
		enemy[enemycount]->Que(situmon, situmonNum);
	}

}