#pragma once
class Player;
class Kayku;
class Enemy;
class GamePlay
{
public:
	
	int count;
	int cunterpng;
	int countNum;
	int kyakucount;
	int enemycount;
private:
	Enemy* enemy[10];
	

	Player* player;
public:
	GamePlay();
	~GamePlay();
	void Draw();
	void Update();
	void CountDawn();
};

