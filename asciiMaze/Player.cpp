#include "Player.hpp"
#include "include/libtcod.hpp"

Player::Player(int x, int y) : value('@')
{
	pos.x = x;
	pos.y = y;
}

Player::~Player()
{
}

void Player::move(int dx, int dy)
{
	if (TCODConsole::root->getChar(pos.x + dx, pos.y) != wall) 
			pos.x += dx;
	if (TCODConsole::root->getChar(pos.x, pos.y + dy) != wall)
			pos.y += dy;
}

void Player::render() const
{
	TCODConsole::root->setChar(pos.x, pos.y, value);
}
