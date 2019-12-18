#include "Player.h"
#include <iostream>

Player::Player()
{
	textLenght = 16;
	textHeight = 21;
	texture.loadFromFile("res/pl.png");
	sprite.setTexture(texture);
	rect = FloatRect(0, 0, textLenght, textHeight);
	rect.left = 100;
	rect.top = 100;
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 5;
	dx = 0.1;
	dy = 0.1;
	speed = 0.1;
	buffer.resize(2);
	loadSound(jump, "res/jump.wav");
	loadSound(hit, "res/hit.wav");
	loadSound(damage, "res/damage.wav");
}

void Player::update(double time, sf::RenderWindow &window, IMap * map)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		dx = -speed;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		dx = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (onGround)
		{
			playSound(jump);
			dy = -0.30;
			onGround = false;
		}
	}

	if (damageTimer.getElapsedTime().asMilliseconds() > 500)
	{
		damaged = false;
	}

	rect.left += dx * time;
	map->collisionX(*this);

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	map->collisionY(*this);

	curFrame += 0.003 * time;

	if (curFrame > 3) curFrame = 0;
	if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
	if (dx < 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)), 0, textLenght, textHeight));
	if (dx > 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)) + textLenght, 0, -textLenght, textHeight));
	if (dy < 0 && onGround == false) sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
	if (dy < 0 && onGround == false && Keyboard::isKeyPressed(Keyboard::Right)) sprite.setTextureRect(IntRect(textLenght * countOfFrames, 0, -textLenght, textHeight));

	sprite.setPosition(rect.left - map->getOfSetX(), rect.top - map->getOfSetY());

	dx = 0;
	window.draw(sprite);
}

bool Player::checkFights(IEnemy & en)
{
	
	if (rect.intersects(en.getRect()) && en.getStatus() && !damaged)
	{
		damaged = true;
		damageTimer.restart();
		damageTimer.getElapsedTime();
		if (!onGround && dy > 0.0007)
		{
			playSound(hit);
			dy -= 0.5;
			en.getDamage();
			return true;
		}
		else
		{
			playSound(damage);
			dy -= 0.3;
			if (en.getRect().left < rect.left)
			{
				dx += 70;
			}
			else
			{
				dx -= 70;
			}
			return false;
		}
	}

}

void Player::getDamage()
{
	HP--;
}
