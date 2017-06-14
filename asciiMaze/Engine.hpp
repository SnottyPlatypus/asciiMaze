#pragma once
#include "Maze.hpp"
#include "Player.hpp"

class Engine
{
public:
	Engine();
	~Engine();
	void update();
	void renderGoalCell() const;
	bool checkForWin() const;
	void render() const;

private:
	Maze *maze;
	Player *player;
	TCOD_key_t key;
	int width;
	int height;
};

