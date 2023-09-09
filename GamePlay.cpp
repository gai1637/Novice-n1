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
	back = Novice::LoadTexture("./Resouse/image/haikeiback.png");
	countMP3 = Novice::LoadAudio("./resouse/Audio/countDown.mp3");
	for (int i = 0; i < 6; i++) {
		situmonF[i] = 0;
	}
	BGM = Novice::LoadAudio("./resouse/Audio/Sparkle!!.wav");
	BGMflag = true;
	situmonM[0]= Novice::LoadTexture("./Resouse/image/moji/situmon1.png");
	situmonM[1]= Novice::LoadTexture("./Resouse/image/moji/situmon2.png");
	situmonM[2]= Novice::LoadTexture("./Resouse/image/moji/situmon3.png");
	situmonM[3]= Novice::LoadTexture("./Resouse/image/moji/situmon4.png");
	situmonM[4]= Novice::LoadTexture("./Resouse/image/moji/situmon5.png");
	situmonM[5]= Novice::LoadTexture("./Resouse/image/moji/situmon6.png");

}
GamePlay::~GamePlay() {
	delete player;
	delete* enemy; 
		
	
	
}
void GamePlay::CountDawn() {
	if (count > 0) {
		if (count % 60 == 0) {
			Novice::PlayAudio(countMP3, 0, 1);
		}
		count--;
		if (count % 60 == 0) {
			countNum--;
			
		}
	}
}
void GamePlay::Update() {
	
	player->Move();
	CountDawn();
	if (count > -60&&count<=0) {
		count--;
	}
	if (count == -60) {
		Numflag = false;
	}
	if (count <= 0) {
		if (BGMflag) {
			BGMflag = false;
			Novice::PlayAudio(BGM, 1, 1);
		}
		enemy[enemycount]->Run();
		if (!enemy[enemycount]->runflag) {
			if (F) {
				situmon = true;
				F = false;
				
				for (int x = 0; x < 6; x++) {
					SitumonFriwake(situmonF, x);
				}
			}
			if (!situmon) {
				situmoncount++;
				if (situmoncount >= 120) {
					situmon = true;
					situmoncount = 0;
					
				}
			}
			if (Novice::IsTriggerMouse(0)) {
				if (situmon) {
					if (sit < 2) {
						if (player->posy > 510 && player->posy < 710) {
							if (player->posx > 20
								&& player->posx < 420) {
								situmonNum = situmonF[0];
								if (sit == 1) {
									situmonNum = situmonF[3];
								}
								situmon = false;
								sit++;
								enemy[enemycount]->aisatuflag = false;
							}
							else if (player->posx > 440 && player->posx < 840) {
								situmonNum = situmonF[1];
								if (sit == 1) {
									situmonNum = situmonF[4];
								}
								situmon = false;
								sit++;
								enemy[enemycount]->aisatuflag = false;
							}
							else if (player->posx > 860 && player->posx < 1260) {
								situmonNum = situmonF[2];
								if (sit == 1) {
									situmonNum = situmonF[5];
								}
								situmon = false;
								sit++;
								enemy[enemycount]->aisatuflag = false;
							}

						}
					}else
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

						
					}
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
void GamePlay::Draw() {
	Q(0, 0, 1280, 720, 1280, 720, back);
	QE(0, 0, 1280, 720,0, 1280, 720, haikei);
	if (!ketudan) {
		enemy[enemycount]->Draw();
	}
	else
	{
		enemy[enemycount]->TaitenDraw(kekka);
	}
	if (situmon&&sit==0) {
		for (int y = 0; y < 3; y++) {
			
			Q(20 + 420 * y, 510, 400, 200, 400, 200, situmonM[situmonF[y] ]);
		}
	}
	if (situmon&&sit==1) {
		
		for (int y = 0; y < 3; y++) {

			Q(20 + 420 * y, 510, 400, 200, 400, 200, situmonM[situmonF[y+3]]);
		}
	}

	if (sit >= 2&&situmon) {
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
	
}
int GamePlay::SitumonFriwake(int *a,int b) {
	a[b] = rand() % 6;
	if (b >= 1) {
		for (int i = b-1; i >= 0; i--) {
			if (a[b] == a[i]&&b!=i) {
				GamePlay::SitumonFriwake(a, b);
			}
		}
	}
	return a[b];
}