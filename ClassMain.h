#pragma once
class GamePlay;
class Explanation;
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
	int titlepng;
public:
	void Update(char* keys);
	void Draw();
	ClassMain();
	~ClassMain();
};

