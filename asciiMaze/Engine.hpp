#pragma once
#include "Maze.hpp"

class Engine
{
public:
	Engine();
	~Engine();
	void render() const;

	Maze *maze;

private:

};

