#pragma once
#include"Vector2.h"
class Kyaku
{
public:
	Vector2 pos;
	bool tenbai;
	int size;
	int png;
public:
	Kyaku(bool a,int b);
	void Run();
	void Draw();
};

