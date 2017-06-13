#pragma once
#include "Cell.hpp"
#include <vector>
#include "Position.hpp"

class Maze
{
public:
	Maze();
	~Maze();
	void generateMaze(Position cell);
	bool anyNonVisitedCell() const;
	void render() const;
	void setNorthPath(int x, int y) const;
	void setSouthPath(int x, int y) const;
	void setEastPath(int x, int y) const;
	void setWestPath(int x, int y) const;

private:
	int width;
	int height;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	Cell *cells;
	Position neighbor;
	Position firstCell;
	Position previousCell;
	int ir;
	TCODRandom *rnd;
	std::vector<int> neighbors;
	std::vector<Position> stack;
};

