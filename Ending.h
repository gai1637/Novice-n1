#pragma once
#include"Vector2.h"
class Ending
{
public:
	Ending();
	void Update();
	void Draw();
private:
	int png[3];
	int countEnd ;
	int countNum ;
	int Enterpng;
	Vector2 pos;
	float sit;
};

