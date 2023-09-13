#include "Ending.h"
#include"Novice.h"
#include<math.h>
#include"func.h"
Ending::Ending() {
	png[0] = Novice::LoadTexture("./Resouse/image/normalEnd1.png");
	png[1] = Novice::LoadTexture("./Resouse/image/normalEnd2.png");
	png[2] = Novice::LoadTexture("./Resouse/image/normalEnd3.png");
	Enterpng= Novice::LoadTexture("./Resouse/image/enter.png");
	BGM = Novice::LoadAudio("./Resouse/Audio/tomoshibi.mp3");
	countEnd = 60;
	countNum = 0;
	pos = { 1280 - 400,360 };
	sit = 0;
	flag = false;
}
void Ending::Update() {
	
	countEnd--;
	if (countEnd <= 0) {
		countNum++;
		if (countNum >= 3) {
			countNum = 0;
		}
		countEnd = 60;
	}
	pos.y += sinf(sit);
	sit+=0.1f;
}
void Ending::Draw() {
	QE(0, 0, 1280, 720, 0, 1280, 720, png[countNum]);
	Q((int)pos.x,(int) pos.y, 400, 360, 400, 360, Enterpng);
	
}
void Ending::Reset() {
	countEnd = 60;
	countNum = 0;
	pos = { 1280 - 400,360 };
	sit = 0;
	flag = false;
	Novice::StopAudio(BGM);
}