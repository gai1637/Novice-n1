#include "Game.h"
#include"Player.h"
Game::Game() {
	player = new Player;
	count = 180;
	countNum = 3;
}
void Game::CountDawn() {
	if (count > 0) {
		count--;
		if (count % 60 == 0) {
			countNum--;
		}
	}
}
void Game::Update() {
	CountDawn();
	if (count <= 0) {

	}
}