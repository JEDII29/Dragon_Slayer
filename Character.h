#pragma once
class Character
{
public:
	int X;
	int Y;
};

class Player : public Character
{
public:
	Player();
	Player(int x, int y);
	void move();
};
