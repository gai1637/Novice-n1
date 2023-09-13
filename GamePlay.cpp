#include "GamePlay.h"
#include"Player.h"
#include<time.h>
#include"Novice.h"
#include"Enemy.h"
#include"func.h"
#include<math.h>

GamePlay::GamePlay() {
	LODE();
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
	
	for (int i = 0; i < 6; i++) {
		situmonF[i] = 0;
	}
	BGM = Novice::LoadAudio("./resouse/Audio/Sparkle!!.wav");
	BGMflag = true;
	errorcount = 0;
	tenbaicount=0;
	playercoount=0;
	errorflag = false;
	wariai = 0;
	tebaiDrawflag=false;
	playerDrawflag=false;
	pasentflag=false;
	animecount = 120;
	tebaiRandamflag=true;
	playerRandamflag=true;
	pasentRandamflag=true;
	pasentDrawflag=false;
	site = 0;
	tenbaisize=100;
	playersize=100;
	pasentsize=150;
}
GamePlay::~GamePlay() {
	delete player;
	delete* enemy; 
		
	
	
}
void GamePlay::LODE() {
	Num[0] = Novice::LoadTexture("./Resouse/image/0.png");
	Num[1] = Novice::LoadTexture("./Resouse/image/1.png");
	Num[2] = Novice::LoadTexture("./Resouse/image/2.png");
	Num[3] = Novice::LoadTexture("./Resouse/image/3.png");
	Num[4] = Novice::LoadTexture("./Resouse/image/4.png");
	Num[5] = Novice::LoadTexture("./Resouse/image/5.png");
	Num[6] = Novice::LoadTexture("./Resouse/image/6.png");
	Num[7] = Novice::LoadTexture("./Resouse/image/7.png");
	Num[8] = Novice::LoadTexture("./Resouse/image/8.png");
	Num[9] = Novice::LoadTexture("./Resouse/image/9.png");
	hitopng= Novice::LoadTexture("./Resouse/image/hito.png");
	papng= Novice::LoadTexture("./Resouse/image/pa.png");
	haikei = Novice::LoadTexture("./Resouse/image/haikei.png");
	back = Novice::LoadTexture("./Resouse/image/haikeiback.png");
	countMP3 = Novice::LoadAudio("./resouse/Audio/countDown.mp3");
	situmonM[0] = Novice::LoadTexture("./Resouse/image/moji/situmon1.png");
	situmonM[1] = Novice::LoadTexture("./Resouse/image/moji/situmon2.png");
	situmonM[2] = Novice::LoadTexture("./Resouse/image/moji/situmon3.png");
	situmonM[3] = Novice::LoadTexture("./Resouse/image/moji/situmon4.png");
	situmonM[4] = Novice::LoadTexture("./Resouse/image/moji/situmon5.png");
	situmonM[5] = Novice::LoadTexture("./Resouse/image/moji/situmon6.png");
	kekkapng[0] = Novice::LoadTexture("./Resouse/image/moji/uru.png");
	kekkapng[1] = Novice::LoadTexture("./Resouse/image/moji/uranai.png");
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
	if (count <= 0&&enemycount<10) {
		
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
									if (enemy[enemycount]->tenbai==0) {
										enemy[enemycount]->seitou = true;
									}else
									{
										enemy[enemycount]->seitou = false;
									}
								}
							if (player->posx >= 760
									&& player->posx <= 1160) {
									kekka = false;
									ketudan = true;
									if (enemy[enemycount]->tenbai==1) {
										enemy[enemycount]->seitou = true;
									}
									else
									{
										enemy[enemycount]->seitou = false;
									}
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
else{
	if (!errorflag) {
		
		
		tebaiDrawflag = true;
		animecount = 120;
		for (int a = 0; a < 10; a++) {
			if (enemy[a]->tenbai) {
				tenbaicount++;
			}
			else
			{
				playercoount++;
			}
		}
		
		errorflag = true;
	}
	if (tebaiDrawflag) {
		if(tebaiRandamflag){
			animecount--;
			if (animecount <= 0) {
				animecount = 120;
				
				playerDrawflag = true;
				tebaiRandamflag = false;
			}
		}
		else
		{
			tenbaisize += sinf(site);
		}
		
	}
	if (playerDrawflag) {
		if (playerRandamflag) {
			animecount--;
			if (animecount <= 0) {
				animecount = 120;
				playerRandamflag = false;
				pasentDrawflag=true;
			}
		}
		else
		{
			playersize += sinf(site);
		}
	}
	if (pasentDrawflag) {
		if (pasentRandamflag) {
			animecount--;
			if (animecount <= 0) {
				for (int a = 0; a < 10; a++) {
					if (!enemy[a]->seitou) {
						errorcount++;
					}
				}
				wariai = 10 - errorcount;
				pasentRandamflag = false;
			}
		}
		else
		{
			pasentsize += sinf(site);
		}

	}
	}
	site += 0.1f;
}
void GamePlay::Draw() {
	Q(0, 0, 1280, 720, 1280, 720, back);
	QE(0, 0, 1280, 720,0, 1280, 720, haikei);
	if (!ketudan && enemycount < 10) {
		enemy[enemycount]->Draw();
	}
	if(ketudan)
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
		
		Q(120, 510, 400, 200, 400, 200, kekkapng[0]);
		Q(760, 510, 400, 200, 400, 200, kekkapng[1]);

	}
	if (!F) {
		enemy[enemycount]->Que(situmon, situmonNum);
	}
	if(count>0)
	Q(640 - 100, 200, 200, 400, 200, 400, Num[countNum]);
	if (Numflag&& count < 0) {

	}
	if (enemycount > 9) {
		if (tebaiDrawflag) {
			if (tebaiRandamflag) {
				Q(300, 80, tenbaisize, tenbaisize * 2, 200, 400, Num[rand() % 10]);
			}
			else
			{
				Q(300, 80, tenbaisize, tenbaisize * 2, 200, 400, Num[tenbaicount]);
			}
			Q(426, 80, 200, 200, 200, 200, hitopng);
		}
		if (playerDrawflag) {
			if (playerRandamflag) {
				Q(725, 80, playersize, playersize * 2, 200, 400, Num[rand() % 10]);
			}
			else {
				Q(725, 80, playersize, playersize * 2, 200, 400, Num[playercoount]);
			}
			Q(852, 80, 200, 200, 200, 200, hitopng);
		}
		if (pasentDrawflag) {
			if (pasentRandamflag) {
				Q(640 - 260, 360, pasentsize, pasentsize * 2, 200, 400, Num[rand() % 9]);
				Q(640 - 140, 360, pasentsize, pasentsize * 2, 200, 400, Num[rand() % 9]);
			}
			else if(wariai==10)
			{
				
				Q(640 - 380, 360, pasentsize, pasentsize * 2, 200, 400, Num[wariai/10]);
				Q(640 - 260, 360, pasentsize, pasentsize * 2, 200, 400, Num[0]);
				Q(640 - 140, 360, pasentsize, pasentsize * 2, 200, 400, Num[0]);
			}
			else
			{
				Q(640 - 260, 360, pasentsize, pasentsize * 2, 200, 400, Num[wariai]);
				Q(640 - 140, 360, pasentsize, pasentsize * 2, 200, 400, Num[0]);
			}
			
			Q(640, 440, 200, 200, 200, 200, papng);

		}

	}
	Novice::ScreenPrintf(0, 0, "%d", errorcount);
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
void GamePlay::Reset() {
	sit = 0;
	
	count = 180;
	countNum = 3;
	for (int a = 0; a < 10; a++) {
		enemy[a]->pos = { 1280,100 };
		
	}
	enemycount = 0;
	Numflag = true;
	situmon = false;
	situmoncount = 0;
	F = true;
	ketudan = false;
	kekka = false;
	tenbaicount=0;
	playercoount=0;
	errorcount = 0;
	errorflag = false;
	tebaiDrawflag=false;
	playerDrawflag=false;
	pasentflag=false;
	animecount = 120;
	tebaiRandamflag = true;
	playerRandamflag = true;
	pasentRandamflag=true;
	pasentDrawflag=false;
	site = 0;
	tenbaisize = 100;
	playersize = 100;
	pasentsize = 150;
}