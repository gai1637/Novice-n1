#pragma once
#include"Vector2.h"

class Enemy
{
public:
	Vector2 pos;
	int tenbai;
	int size;
	int png;
public:
	Enemy();
	void Run();
	void Draw();
};

