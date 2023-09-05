#pragma once
class Player;
class Game
{
public:
	Player *player;
	int count;
	int cunterpng;
	int countNum;
	int kyakucount;
public:
	Game();
	void Draw();
	void Update();
	void CountDawn();
};

