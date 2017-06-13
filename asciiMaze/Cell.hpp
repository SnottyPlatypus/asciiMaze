#pragma once
#include "include/libtcod.hpp"

class Cell
{
public:
	Cell();
	~Cell();
	void printCell(int x, int y) const;
	void setNorthWall(bool set);
	void setSouthWall(bool set);
	void setEastWall(bool set);
	void setWestWall(bool set);
	void setVisited(bool set);
	bool getVisited() const;

private:
	bool n;
	bool s;
	bool e;
	bool w;
	bool visited;
	int size;
	const int wall = TCOD_CHAR_BLOCK3;
};

