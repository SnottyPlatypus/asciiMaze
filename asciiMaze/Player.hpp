#pragma once
#include "include/libtcod.hpp"
#include "Position.hpp"

class Player
{
public:
	Player(int x, int y);
	~Player();
	void move(int dx, int dy);
	void render() const;

	Position pos;
	char value;

private:
	const int wall = TCOD_CHAR_BLOCK3;
};

