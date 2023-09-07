#include "ClassMain.h"
#include"GamePlay.h"
#include"Novice.h"
#include"Explanation.h"
#include<time.h>
ClassMain::ClassMain() {
	srand((unsigned int)time(nullptr));
	game = new GamePlay;
	exp = new Explanation;
	scene = Title;
}
ClassMain::~ClassMain() {
	delete game;
	delete exp;
}
void ClassMain::Update(char* keys, char* prekeys) {
	switch (scene)
	{
	case Title:
		if (Novice::IsTriggerMouse) {
			scene = Exp;
		}
		break;
	case Exp:
		if (keys[DIK_S]) {
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