#include "ClassMain.h"
#include"GamePlay.h"
#include"Novice.h"
#include"Explanation.h"
#include<time.h>
#include"Ending.h"
ClassMain::ClassMain() {
	srand((unsigned int)time(nullptr));
	game = new GamePlay;
	exp = new Explanation;
	end = new Ending;
	scene = Title;
	skipcount = 120;
	titlepng = Novice::LoadTexture("./Resouse/image/title.png");
	titleBGM = Novice::LoadAudio("./Resouse/Audio/title.mp3");
	BGMflag = false;
}
ClassMain::~ClassMain() {
	delete game;
	delete exp;
	delete end;
}
void ClassMain::Update(char* keys) {
	switch (scene)
	{
	case Title:
		if (Novice::IsTriggerMouse(0)) {
			/*Novice::StopAudio(titleBGM);*/
			scene = Exp;
			game->Reset();
			exp->Reset();
			
		}
		/*if (!BGMflag) {
			BGMflag = true;
			Novice::PlayAudio(titleBGM, 1, 1);
			
		}*/
		break;
	case Exp:
		if (keys[DIK_S]) {
			skipcount--;
			if (skipcount <= 0) {
				skipcount = 120;
				scene = Game;
			}
		}
		exp->Update();
		if (exp->count >= 7) {
			scene = Game;
		}
		break;
	case Game:
		game->Update();
		if (!game->pasentRandamflag && game->pasentDrawflag) {
			if (keys[DIK_RETURN]) {
				scene = End;
				Novice::StopAudio(game->BGM);
			}
		}
		/*if (game->enemycount>=10) {
			scene = End;
			Novice::StopAudio(game->BGM);
		}*/
		break;
	case End:
		end->Update();
		if (keys[DIK_RETURN]) {
			scene = Title;
			BGMflag = false;
			end->Reset();

		}
		
		break;
	
	}
}
void ClassMain::Draw() {
	switch (scene)
	{
	case Title:
		Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720,titlepng, WHITE);
		break;
	case Exp:
		exp->Draw();
		break;
	case Game:
		game->Draw();
		break;
	case End:
		end->Draw();
		break;
	default:
		break;
	}
}