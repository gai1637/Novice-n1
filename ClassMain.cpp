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
	BGMHandle = -1;
	GamePLayHandle = -1;
	EndHandle = -1;
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
		if (!Novice::IsPlayingAudio(BGMHandle))
			BGMHandle = Novice::PlayAudio(titleBGM, 1, 1);

		if (Novice::IsTriggerMouse(0)) {
			Novice::StopAudio(BGMHandle);
			scene = Exp;
			game->Reset();
			exp->Reset();
			
		}
		
		
		break;
	case Exp:
		if (keys[DIK_S]) {
			skipcount--;
			if (skipcount <= 0) {
				skipcount = 120;
				scene = Game;
			}
		}
		else
		{
			skipcount;
		}

		exp->Update();
		if (exp->count >= 7) {
			scene = Game;
		}
		break;
	case Game:
		game->Update();
		if (game->count <= 0 && !Novice::IsPlayingAudio(GamePLayHandle)) {
			GamePLayHandle = Novice::PlayAudio(game->BGM, 1, 1);
		}
		if (!game->pasentRandamflag && game->pasentDrawflag) {
			if (Novice::IsTriggerMouse(0)) {
				scene = End;
				Novice::StopAudio(GamePLayHandle);
			}
		}
		
		break;
	case End:
		end->Update();
		if (Novice::IsPlayingAudio(EndHandle)) {
			EndHandle = Novice::PlayAudio(end->BGM, 1, 1);
		}
		if (keys[DIK_RETURN]) {
			scene = Title;
			BGMflag = false;
			end->Reset();
			Novice::StopAudio(EndHandle);
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