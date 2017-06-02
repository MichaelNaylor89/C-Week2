#include "game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "My Game");
	window->setVerticalSyncEnabled(true);
	background.loadFromFile("Assets/background.png");
	
}

void Game::Init()
{
	// do any one-time game initialization here
	avatar = new Avatar(this);
}

void Game::Update()
{
	// once-per-frame update
	avatar->Update();
}

void Game::Display()
{
	// draw everything here
	sf::Sprite background1;
	background1.setTexture(background);
	background1.setTextureRect(sf::IntRect( 0, 0, background.getSize().x, background.getSize().y ));
	background1.setPosition(sf::Vector2f(0, 0));
	GetSFMLWindow()->draw(background1);
	avatar->Draw();
}

void Game::Run()
{
	Init();

	while (window->isOpen())
	{
		// Process events
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		// update the world
		Update();
		// draw the world
		Display();
		window->display();
		// kill window if escape is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();
	}
	delete window;
}

sf::RenderWindow* Game::GetSFMLWindow()
{
	return window;
}