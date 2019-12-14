#include "Turtle.h"
#include "IMap.h"
#include<iostream>
Turtle::Turtle()
{
	textLenght = 21;
	textHeight = 18;
	texture.loadFromFile("res/turtle.png");
	sprite.setTexture(texture);
	rect = FloatRect(0, 0, textLenght, textHeight);
	rect.left = rand() % 200 + 100;
	rect.top = 100;
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 5;
	dx = 0.1;
	dy = 0.1;
	speed = 0.05;
}

void Turtle::update(double time, sf::RenderWindow& window, IMap* map)
{
	if (damaged)
	{
		if (HP <= 0 && alive) kill();
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
		if (curFrame > countOfFrames - 1) curFrame = 0;
		if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
		if (dx > 0) sprite.setTextureRect(IntRect(textLenght * int(curFrame), 0, textLenght, textHeight));
		if (dx < 0) sprite.setTextureRect(IntRect(textLenght * int(curFrame) + textLenght, 0, -textLenght, textHeight));
	}
	else if (damaged)
	{
		sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
		
	}
	{
		if (rect.top > window.getSize().y)
			exist = false;
	}
	sprite.setPosition(rect.left - map->getOfSetX(), rect.top - map->getOfSetY());

	dx = 0;
	window.draw(sprite);
}

void Turtle::getDamage()
{
	damaged = true;
	damageTimer.restart();
	damageTimer.getElapsedTime();
	HP--;
}

sf::FloatRect Turtle::getRect()
{
	return this->rect;
}

bool Turtle::getStatus()
{
	return alive;
}

void Turtle::kill()
{
	sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
	dy = -0.4;
	onGround = false;
	alive = false;
}

