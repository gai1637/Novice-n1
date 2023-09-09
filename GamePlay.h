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
	int situmonF[6];
	
private:
	Enemy* enemy[10];
	Player* player;
	int haikei;
	int Num[4];
	int back;
	int countMP3;
	int BGM;
	bool BGMflag;
	int situmonM[6];
public:
	GamePlay();
	~GamePlay();
	void Draw();
	void Update();
	void CountDawn();
	int SitumonFriwake(int *a,int b);
};

