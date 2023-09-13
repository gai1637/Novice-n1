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
	int moji[5];
	int open;
	int close;
	int heya;
	int memo;
	int kami;
	void LODE();
public:
	Explanation();
	void Update();
	void Draw();
	void Reset();
};

