#include "ClassMain.h"
#include"GamePlay.h"
#include"Novice.h"
#include"Explanation.h"
#include<time.h>
ClassMain::ClassMain() {
	srand((unsigned int)time(nullptr));
	game = new GamePlay;
	exp = new Explanation;
}
ClassMain::~ClassMain() {
	delete game;
}
void ClassMain::Update(char* keys, char* prekeys) {
	switch (scene)
	{
	case Title:
		break;
	case Exp:
		break;
	case Game:
		game->Update();
		break;
	case End:
		break;
	default:
		break;
	}
}