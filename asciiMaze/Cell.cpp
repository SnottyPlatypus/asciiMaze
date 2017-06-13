#include "Cell.hpp"
#include "include/libtcod.hpp"

Cell::Cell() : n(true), s(true), e(true), w(true), visited(false), size(3)
{
}

Cell::~Cell()
{
}

void Cell::printCell(int x, int y) const
{
	if (n)
		TCODConsole::root->setChar(x, y - 1, wall);
	if (s)
		TCODConsole::root->setChar(x, y + 1, wall);
	if (e)
		TCODConsole::root->setChar(x + 1, y, wall);
	if (w)
		TCODConsole::root->setChar(x - 1, y, wall);
	TCODConsole::root->setChar(x - 1, y - 1, wall);
	TCODConsole::root->setChar(x - 1, y + 1, wall);
	TCODConsole::root->setChar(x + 1, y - 1, wall);
	TCODConsole::root->setChar(x + 1, y + 1, wall);
}

void Cell::setNorthWall(bool set)
{
	n = set;
}

void Cell::setSouthWall(bool set)
{
	s = set;
}

void Cell::setEastWall(bool set)
{
	e = set;
}

void Cell::setWestWall(bool set)
{
	w = set;
}

void Cell::setVisited(bool set)
{
	visited = set;
}

bool Cell::getVisited() const
{
	return visited;
}
