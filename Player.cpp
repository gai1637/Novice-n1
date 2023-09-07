#include "Player.h"
#include"Novice.h"
Player::Player() {
	posx = 0;
	posy = 0;
}
void Player::Move() {
	Novice::GetMousePosition(&posx, &posy);

}