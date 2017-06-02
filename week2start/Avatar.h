#pragma once

#include "stdafx.h"
class Game;

class Avatar
{
	int tick = 0;

	bool walking = false;

	const int DIRECTION_LEFT = 0;
	const int DIRECTION_RIGHT = 1;
	const int DIRECTION_UP = 2;
	const int DIRECTION_DOWN = 3;

	int direction = DIRECTION_LEFT;

	sf::Texture spriteSheet;
	sf::IntRect textureRects[12];

	int posX;
	int posY;

	Game* parent;

public:
	Avatar(Game *newParent);
	void Update();
	void Draw();
};
