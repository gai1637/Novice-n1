#pragma once
class Player;
class Kayku;
class Enemy;
class GamePlay
{
public:
	int count;
	int countNum;
	int enemycount;
	bool Numflag;
	bool situmon;
	int situmonNum = 0;
	int situmoncount = 0;
	bool F;
	int sit;
	bool ketudan;
	bool kekka;
	
private:
	Enemy* enemy[10];
	Player* player;
	int haikei;
	int Num[4];
	int back;
public:
	GamePlay();
	~GamePlay();
	void Draw();
	void Update();
	void CountDawn();
};

