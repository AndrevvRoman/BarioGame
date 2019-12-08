#include "Player.h"

Player::Player()
{
	textLenght = 16;
	textHeight = 21;
	pl.loadFromFile("res/pl.png");
	sprite.setTexture(pl);
	rect = FloatRect(0, 0, textLenght, textHeight);
	rect.left = 100;
	rect.top = 100;
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 5;
	dx = 0.1;
	dy = 0.1;
}

void Player::update(double time, sf::RenderWindow &window)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		dx = -0.1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		dx = 0.1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (onGround)
		{
			dy = -0.25;
			onGround = false;
		}
	}

	rect.left += dx * time;

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;

	curFrame += 0.003 * time;

	if (curFrame > 3) curFrame = 0;
	if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
	if (dx < 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)), 0, textLenght, textHeight));
	if (dx > 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)) + textLenght, 0, -textLenght, textHeight));
	if (dy < 0 && onGround == false) sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
	if (dy < 0 && onGround == false && Keyboard::isKeyPressed(Keyboard::Right)) sprite.setTextureRect(IntRect(textLenght * countOfFrames, 0, -textLenght, textHeight));

	sprite.setPosition(rect.left, rect.top);

	dx = 0;
}
