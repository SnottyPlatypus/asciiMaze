#include "Engine.hpp"
#include "include/libtcod.hpp"

Engine::Engine() : width(79), height(49)
{
	maze = new Maze();
	player = new Player(1, 1);
	TCODConsole::initRoot(width, height, "asciiMaze");
}

Engine::~Engine()
{
	delete maze;
	delete player;
}

void Engine::update()
{
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);
	switch(key.vk) {
	case TCODK_UP: player->move(0, -1); break;
	case TCODK_DOWN: player->move(0, 1); break;
	case TCODK_LEFT: player->move(-1, 0); break;
	case TCODK_RIGHT: player->move(1, 0); break;
	default: break;
	}
}

void Engine::renderGoalCell() const
{
	const TCODColor firstCell(150, 0, 0);
	TCODConsole::root->setCharBackground(1, 1, firstCell);
	const TCODColor lastCell(0, 150, 0);
	TCODConsole::root->setCharBackground(width - 2, height - 2, lastCell);
}

bool Engine::checkForWin() const
{
	if (player->pos.x == width - 2 && player->pos.y == height - 2)
		return true;
	return false;
}

void Engine::render() const
{
	TCODConsole::root->clear();
	maze->render();
	player->render();
	renderGoalCell();
	if(checkForWin())
		TCODConsole::root->printEx(40, 25, TCOD_BKGND_NONE, TCOD_CENTER, "You won !");
	TCODConsole::root->flush();
}
