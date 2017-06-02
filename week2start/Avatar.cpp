#include "Avatar.h"
#include "Game.h"

Avatar::Avatar(Game *newParent) : parent(newParent)
{
	posX = parent->GetSFMLWindow()->getSize().x / 2;
	posY = parent->GetSFMLWindow()->getSize().y / 2;

	spriteSheet.loadFromFile("Assets/universal-lpc-sprite_male_01_walk-3frame.png");

	int textureWidth = spriteSheet.getSize().x;
	int textureHeight = spriteSheet.getSize().y;
	int spriteWidth = textureWidth / 3;
	int spriteHeight = textureHeight / 4;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			textureRects[j * 3 + i] =
				sf::IntRect(spriteWidth*i, spriteHeight*j, spriteWidth, spriteHeight);
		}
	}

}

void Avatar::Update()
{
	tick++;

	walking = false;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && posX >= 10)
	{
		posX -= 3;
		direction = DIRECTION_RIGHT;
		walking = true;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && posX <= (parent->GetSFMLWindow()->getSize().x)-60)
	{
		posX += 3;
		direction  = DIRECTION_LEFT;
		walking = true;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && posY >= 10)
	{
		posY -= 3;
		direction = DIRECTION_UP;
		walking = true;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && posY <= (parent->GetSFMLWindow()->getSize().y)-90)
	{
		posY += 3;
		direction = DIRECTION_DOWN;
		walking = true;
	}
}

void Avatar::Draw()
{
	int spriteIndex = 0;
	int spriteOffset = 0;
	int animSpeed = 3;
	int animFrame = (tick / animSpeed) % 4;
	
	

	if (direction == DIRECTION_LEFT)
		spriteIndex = 4;
	else if (direction == DIRECTION_RIGHT)
		spriteIndex = 10;
	else if (direction == DIRECTION_UP)
		spriteIndex = 1;
	else if (direction == DIRECTION_DOWN)
		spriteIndex = 7;

	if (walking)
	{
		if (animFrame == 1)
			spriteOffset = -1;
		else if (animFrame == 3)
			spriteOffset = 1;
	}
	spriteIndex = spriteIndex + spriteOffset;

	sf::Sprite sprite;
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(textureRects[spriteIndex]);
	sprite.setPosition(sf::Vector2f(posX, posY));
	parent->GetSFMLWindow()->draw(sprite);

	

}