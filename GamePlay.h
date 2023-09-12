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
	int BGM;
	int tenbaicount;
	int playercoount;
	int errorcount;
	bool errorflag;
	int wariai;
	int animecount;
	bool tebaiDrawflag;
	bool playerDrawflag;
	bool tebaiRandamflag;
	bool playerRandamflag;

	bool pasentflag;
	bool pasentRandamflag;
	bool pasentDrawflag;
	float site;
	float tenbaisize;
	float playersize;
	float pasentsize;


private:
	Enemy* enemy[10];
	Player* player;
	int haikei;
	
	int back;
	int countMP3;
	int Num[10];
	bool BGMflag;
	int situmonM[6];
	int kekkapng[2];
	int hitopng;
	int papng;
public:
	GamePlay();
	~GamePlay();
	void Draw();
	void Update();
	void CountDawn();
	int SitumonFriwake(int *a,int b);
	void Reset();
	void LODE();
};

