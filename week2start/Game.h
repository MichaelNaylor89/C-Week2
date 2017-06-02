#pragma once
#include "stdafx.h"
#include "Avatar.h"

class Game
{
	sf::Texture background;
	sf::RenderWindow* window;
	void Init();
	void Update();
	void Display();
	
public:
	Game();
	void Run();
	sf::RenderWindow* GetSFMLWindow();
	Avatar *avatar;
};