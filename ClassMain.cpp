#include "ClassMain.h"
#include"GamePlay.h"
#include"Novice.h"
#include"Explanation.h"
#include<time.h>
ClassMain::ClassMain() {
	srand((unsigned int)time(nullptr));
	game = new GamePlay;
	exp = new Explanation;
	scene = Exp;
	titlepng = 0;
	skipcount = 120;
}
ClassMain::~ClassMain() {
	delete game;
	delete exp;
}
void ClassMain::Update(char* keys) {
	switch (scene)
	{
	case Title:
		if (Novice::IsTriggerMouse(0)) {
			scene = Exp;
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
		exp->Update();
		if (exp->count >= 5) {
			scene = Game;
		}
		break;
	case Game:
		game->Update();
		if (game->enemycount>=10) {
			scene = End;
		}
		break;
	case End:
		
		break;
	default:
		break;
	}
}
void ClassMain::Draw() {
	switch (scene)
	{
	case Title:
		break;
	case Exp:
		exp->Draw();
		break;
	case Game:
		game->Draw();
		break;
	case End:

		break;
	default:
		break;
	}
}