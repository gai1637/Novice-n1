#include "Enemy.h"
#include"Novice.h"
#include"func.h"

Enemy::Enemy() {
	pos = { 1280,100 };
	tenbai = rand() % 2;
	size = 200;
	png = rand() % 5;
	aisatu = 0;
	switch (png)
	{
	case 0:
		png = Novice::LoadTexture("./Resouse/image/LADY.png");
		aisatu = Novice::LoadTexture("./Resouse/image/moji/Manaisatu.png");
		break;
	case 1:
		png = Novice::LoadTexture("./Resouse/image/OTAKU.png");
		aisatu = Novice::LoadTexture("./Resouse/image/moji/Otakuaisatu.png");
		break;
	case 2:
		png = Novice::LoadTexture("./Resouse/image/MAN.png");
		aisatu = Novice::LoadTexture("./Resouse/image/moji/Manaisatu.png");
		break;
	case 3:
		png = Novice::LoadTexture("./Resouse/image/BOY.png");
		aisatu = Novice::LoadTexture("./Resouse/image/moji/Boyaisatu.png");
		break;
	case 4:
		png = Novice::LoadTexture("./Resouse/image/SHADY.png");
		aisatu = Novice::LoadTexture("./Resouse/image/moji/aisatu.png");
		break;
	}
	runflag=true;
	endflag=false;
	aisatuflag = false;
	seitou = true;
	hukidasi=Novice::LoadTexture("./Resouse/image/Lines.png");
	hentou[0] = Novice::LoadTexture("./Resouse/image/moji/nanjamon.png");
	hentou[1] = Novice::LoadTexture("./Resouse/image/moji/hikarinezumi.png");
	hentou[2] = Novice::LoadTexture("./Resouse/image/moji/gekkouga.png");
	hentou[3] = Novice::LoadTexture("./Resouse/image/moji/maisu.png");
	hentou[4] = Novice::LoadTexture("./Resouse/image/moji/satoG.png");
	hentou[5] = Novice::LoadTexture("./Resouse/image/moji/rikosu.png");
	hentou[6] = Novice::LoadTexture("./Resouse/image/moji/siteiru.png");


	

}
void Enemy::Run() {
	if (runflag) {
		pos.x-=5;
	}
	if (pos.x <= 640 - (float)size / 2&&runflag) {
		runflag = false;
		aisatuflag = true;
	}
}
void Enemy::Draw() {
	if (runflag) {
		QE((int)pos.x, (int)pos.y, size,400, 200,200, 400, png);
	}
	else
	{
		Q((int)pos.x, (int)pos.y, size, 400, 200, 400, png);
		Q(1280 - 300, 0, 300, 200, 300, 200, hukidasi);
		
		
	}
	
	
}
void Enemy::Que(bool flag,int num) {
	if(flag&&!runflag&&aisatuflag)
	Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, aisatu);
	if (!flag) {
		
		switch (num)
		{
		case 0:
			Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[0]);
			break;
		case 1:
			Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[1]);
			break;
		case 2:
			if (tenbai) {
				Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[0]);
			}
			else
			{
				Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[2]);
			}
			break;
		case 3:
			Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[3]);
			break;
		case 4:
			if (tenbai) {
				Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[4]);
			}
			else
			{
				Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[5]);
			}
			break;
		case 5:
			Q(1280 - (300 - 32), 32, 300 - 32, 200 - 32, 236, 136, hentou[6]);
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