#pragma once
class GamePlay;
class Explanation;
typedef enum Scene {
	Title,
	Exp,
	Game,
	End
};
class ClassMain
{
public:
	GamePlay* game;
	Scene scene;
	Explanation *exp;

public:
	void Update(char* keys, char* prekeys);
	void Draw();
	ClassMain();
	~ClassMain();
};

