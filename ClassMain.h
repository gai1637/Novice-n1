#pragma once
class GamePlay;
class Explanation;
class Ending;
typedef enum Scene {
	Title,
	Exp,
	Game,
	End
}scene;
class ClassMain
{
public:
	GamePlay* game;
	Scene scene;
	Explanation *exp;
	Ending *end;
	int titlepng;
	short skipcount;
	int titleBGM;
	bool BGMflag;
public:
	void Update(char* keys);
	void Draw();
	ClassMain();
	~ClassMain();
};

