#include "Engine.hpp"
#include "include/libtcod.hpp"

Engine::Engine()
{
	maze = new Maze();
	TCODConsole::initRoot(80, 50, "asciiMaze");
}

Engine::~Engine()
{
}

void Engine::render() const
{
	TCODConsole::root->clear();
	maze->render();
	TCODConsole::root->flush();
}
