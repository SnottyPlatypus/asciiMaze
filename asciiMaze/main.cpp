#include "include/libtcod.hpp"
#include "Engine.hpp"

Engine engine;
int main()
{
	while(!TCODConsole::isWindowClosed()) {
		engine.render();
	}
	return 0;
}