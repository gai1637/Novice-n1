#pragma once
#include"Vector2.h"

class Enemy
{
public:
	Vector2 pos;
	int tenbai;
	int size;
	int png;
	bool runflag;
	bool endflag;
public:
	Enemy();
	void Run();
	void Draw();
	void Que(bool flag, int num);
	void Taiten();
	void TaitenDraw(bool f);

};

