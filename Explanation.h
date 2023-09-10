#pragma once
class Explanation
{
public:
	bool openflag;
	bool closeflag;
	int count;
	int timer;
private:
	int haikei;
	int moji[4];
	int open;
	int close;
	void LODE();
public:
	Explanation();
	void Update();
	void Draw();
};

