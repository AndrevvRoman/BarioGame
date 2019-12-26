#include "Mushroom.h"
#include <iostream>

Mushroom::Mushroom()
{
	textLenght = 16;
	textHeight = 16;
	texture.loadFromFile("res/mushroom.png");
	sprite.setTexture(texture);
	rect = FloatRect(rand() % 1500, 25, textLenght, textHeight);
	std::cout << "Bonus rect left = " << rect.left << std::endl;
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 1;
	dx = 0;
	dy = 0;
	speed = 0;
}

bool Mushroom::update(double time, sf::RenderWindow& window, IMap* map)
{
	rect.left += dx * time;
	map->collisionX(*this);

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	map->collisionY(*this);

	curFrame += 0.003 * time;
	if (alive)
	{
		sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));

		sprite.setPosition(rect.left - map->getOfSetX(), rect.top - map->getOfSetY());

		dx = 0;
		window.draw(sprite);
	}
	return true;
}

uint16_t Mushroom::getBonus()
{
	alive = false;
	return BonusFilter::speed;
}

bool Mushroom::getStatus()
{
	return alive;
}

sf::FloatRect Mushroom::getRect()
{
	return rect;
}
