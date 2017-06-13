#include "Maze.hpp"
#include "Cell.hpp"
#include "include/libtcod.hpp"
#include <vector>
#include <iostream>
#include "Position.hpp"

Maze::Maze() : width(10), height(10), ir(0)
{
	cells = new Cell[width * height];
	rnd = new TCODRandom();
	//firstCell.x = rnd->getInt(0, width - 1);
	//firstCell.y = rnd->getInt(0, height - 1);
	generateMaze(firstCell);
}

Maze::~Maze()
{ 
	delete cells;
}

void Maze::generateMaze(Position cell)
{
	cells[cell.x + cell.y * width].setVisited(true);
	for (int i = 0; i < 4; i++) {
		neighbor.x = cell.x + dx[i];
		neighbor.y = cell.y + dy[i];
		if (neighbor.x >= 0 && neighbor.x < width && neighbor.y >= 0 && neighbor.y < height)
			if (!cells[neighbor.x + neighbor.y * width].getVisited())
				neighbors.push_back(i);
	}
	if (!neighbors.empty()) {
		stack.push_back(cell);
		ir = neighbors[rnd->getInt(0, neighbors.size() - 1)];
		if (dx[ir] == 0 && dy[ir] == -1)
			setNorthPath(cell.x, cell.y);
		if (dx[ir] == 0 && dy[ir] == 1)
			setSouthPath(cell.x, cell.y);
		if (dx[ir] == 1 && dy[ir] == 0)
			setEastPath(cell.x, cell.y);
		if (dx[ir] == -1 && dy[ir] == 0)
			setWestPath(cell.x, cell.y);
		cell.x += dx[ir];
		cell.y += dy[ir];
		neighbors.clear();
		generateMaze(cell);
	}
	else if(!stack.empty()) {
		cell = stack.back();
		stack.pop_back();
		generateMaze(cell);
	}
}

bool Maze::anyNonVisitedCell() const
{
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			if (!cells[i + j * width].getVisited())
				return false;
		}
	}
	return true;
}

void Maze::render() const
{
	for(int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cells[i + j * width].printCell(i * 2 + 1, j * 2 + 1);
		}
	}
}

void Maze::setNorthPath(int x, int y) const
{
	cells[x + y * width].setNorthWall(false);
	cells[x + (y - 1) * width].setSouthWall(false);
}

void Maze::setSouthPath(int x, int y) const
{
	cells[x + y * width].setSouthWall(false);
	cells[x + (y + 1) * width].setNorthWall(false);
}

void Maze::setEastPath(int x, int y) const
{
	cells[x + y * width].setEastWall(false);
	cells[x + 1 + y * width].setWestWall(false);
}

void Maze::setWestPath(int x, int y) const
{
	cells[x + y * width].setWestWall(false);
	cells[x - 1 + y * width].setEastWall(false);
}
