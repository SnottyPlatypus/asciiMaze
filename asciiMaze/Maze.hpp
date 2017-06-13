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

	Cell *cells;

private:
	int width;
	int height;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	Position neighbour;
	int ir;
	Position firstCell;
	Position previousCell;
	TCODRandom *rnd;
	std::vector<int> neighbours;
	std::vector<Position> visitedCells;
};

