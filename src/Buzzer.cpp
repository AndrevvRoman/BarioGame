#include "Buzzer.h"
#include <iostream>
Buzzer::Buzzer()
{
	textLenght = 32;
	textHeight = 32;
	texture.loadFromFile("res/buzzer.png");
	sprite.setTexture(texture);
	rect = FloatRect(400, 10, textLenght, textHeight);
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 4;
	dx = 0.1;
	dy = 0.1;
	speed = 0.2;
}

bool Buzzer::getStatus()
{
	return alive;
}

bool Buzzer::update(double time, sf::RenderWindow& window, IMap* map)
{
	bool result = false;
	if (damaged)
	{
		if (HP <= 0 && alive)
		{
			kill();
		}
		else if (damageTimer.getElapsedTime().asMilliseconds() > 200)
		{
			damaged = false;
		}
	}

	if (alive && exist && !damaged)
	{
		if (dir) dx = -speed;
		else dx = speed;
		rect.left += dx * time;
		if (map->collisionX(*this)) dir = !dir;
	}
	if (exist)
	{
		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		if (alive) map->collisionY(*this);
	}

	if (alive && !damaged)
	{
		curFrame += 0.003 * time;
		if (curFrame > countOfFrames) curFrame = 0;
		if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
		if (dx < 0) sprite.setTextureRect(IntRect(textLenght * int(curFrame), 0, textLenght, textHeight));
		if (dx > 0) sprite.setTextureRect(IntRect(textLenght * int(curFrame) + textLenght, 0, -textLenght, textHeight));
	}
	else if (damaged)
	{
		sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));

	}
	{
		if (rect.top > window.getSize().y)
		{
			exist = false;
			result = true;
		}
	}
	sprite.setPosition(rect.left - map->getOfSetX(), rect.top - map->getOfSetY());

	dx = 0;
	window.draw(sprite);
	return result;
}

void Buzzer::getDamage()
{
	HP--;
}

sf::FloatRect Buzzer::getRect()
{
	return rect;
}

void Buzzer::getReward()
{
}

void Buzzer::setCoords(double x, double y)
{
	rect.left = x;
	rect.top = y;
}

void Buzzer::kill()
{
	sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
	dy = -0.4;
	onGround = false;
	alive = false;
}
