#include "Explanation.h"
#include"Novice.h"
#include"func.h"
Explanation::Explanation() {
	LODE();
	openflag = true;
	closeflag = true;
	timer = 120;
	count = 0;
}
void Explanation::LODE() {
	haikei = Novice::LoadTexture("./Resouse/image/tutorial/backyard.png");
	moji[0] = Novice::LoadTexture("./Resouse/image/tutorial/tynty1.png");
	moji[1] = Novice::LoadTexture("./Resouse/image/tutorial/tynty2.png");
	moji[2] = Novice::LoadTexture("./Resouse/image/tutorial/tynty3.png");
	moji[3] = Novice::LoadTexture("./Resouse/image/tutorial/tynty4.png");

	open = Novice::LoadAudio("./Resouse/Audio/open.mp3");
	close = Novice::LoadAudio("./Resouse/Audio/close.mp3");

}
void Explanation::Draw() {
	Q(0, 0, 1280, 720, 1280, 720, haikei);
	
	switch (count)
	{
	case 1:
		QE(0, 720 - 150, 1280, 150, 0, 2000, 300, moji[0]);
		break;
	case 2:
		QE(0, 720 - 150, 1280, 150, 0, 2000, 300, moji[1]);
		break;
	case 3:
		QE(0, 720 - 150, 1280, 150, 0, 2000, 300, moji[2]);
		break;
	case 4:
		QE(0, 720 - 150, 1280, 150, 0, 2000, 300, moji[3]);
		break;

	}
}
void Explanation::Update() {
	if (openflag) {
		openflag = false;
		Novice::PlayAudio(open, 0, 1);
	}
	if (Novice::IsPlayingAudio(open) == 0 && closeflag) {
		Novice::PlayAudio(close, 0, 1);
		closeflag = false;
	}
	timer--;
	if (timer <= 0) {
		count++;
		timer = 300;
	}
}
void Explanation::Reset() {
	openflag = true;
	closeflag = true;
	timer = 120;
	count = 0;
}