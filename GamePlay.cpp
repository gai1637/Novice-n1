#include "GamePlay.h"
#include"Player.h"
#include<time.h>
#include"Novice.h"
#include"Enemy.h"
#include"func.h"

GamePlay::GamePlay() {
	sit = 0;
	player = new Player;
	count = 180;
	countNum = 3;
	for (int a = 0; a < 10; a++) {
		enemy[a] = new Enemy;
	}
	enemycount = 0;
	Numflag = true;
	situmon = false;
	situmoncount = 0;
	F = true;
	ketudan = false;
	kekka = false;
	Num[0] = 0;
	Num[1] = Novice::LoadTexture("./Resouse/image/1.png");
	Num[2] = Novice::LoadTexture("./Resouse/image/2.png");
	Num[3] = Novice::LoadTexture("./Resouse/image/3.png");
	
	haikei = Novice::LoadTexture("./Resouse/image/haikei.png");
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
	if (count > -60&&count<=0) {
		count--;
	}
	if (count == -60) {
		Numflag = false;
	}
	if (count <= 0) {
		enemy[enemycount]->Run();
		if (!enemy[enemycount]->runflag) {
			if (F) {
				situmon = true;
				F = false;
			}
			if (!situmon&&sit<=1) {
				situmoncount++;
				if (situmoncount >= 120) {
					situmon = true;
				}
			}
			if (Novice::IsTriggerMouse(0)&&situmon) {
				if (sit < 2) {
					if (player->posy > 510 && player->posy < 710) {
						if (player->posx > 20
							&& player->posx < 420) {
							situmonNum = 0;
							if (sit == 1) {
								situmonNum = 3;
							}
							situmon = false;
							sit++;
						}else if (player->posx > 440&& player->posx > 840) {
							situmonNum = 1;
							if (sit == 1) {
								situmonNum = 4;
							}
							situmon = false;
							sit++;
						}else if (player->posx > 860&& player->posx < 1260) {
							situmonNum = 2;
							if (sit == 1) {
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
	
	/*Q(0, 0, 1280, 720, 1280, 720, haikei);*/
	enemy[enemycount]->Draw();
	if (situmon) {
		Novice::DrawBox(20, 510, 400, 200, 0.f, RED, kFillModeWireFrame);
		Novice::DrawBox(440, 510, 400, 200, 0.f, RED, kFillModeWireFrame);
		Novice::DrawBox(860, 510, 400, 200, 0.f, RED, kFillModeWireFrame);

	}
	if (sit >= 2) {
		Novice::DrawBox(120, 510, 400, 200, 0.f, RED, kFillModeWireFrame);
		Novice::DrawBox(760, 510, 400, 200, 0.f, RED, kFillModeWireFrame);

	}
	if (!F) {
		enemy[enemycount]->Que(situmon, situmonNum);
	}
	if(count>0)
	Q(640 - 100, 200, 200, 400, 200, 400, Num[countNum]);
	if (Numflag&& count < 0) {

	}
	Novice::ScreenPrintf(0, 0, "%d", countNum);
}