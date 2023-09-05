#include "Player.h"
#include"Novice.h"
Player::Player() {
	
}
void Player::Move() {
	Novice::GetMousePosition(&posx, &posy);

}