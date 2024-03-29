#include "Player.h"
#include <iostream>

Player::Player()
{
	textLenght = 16;
	textHeight = 21;
	texture.loadFromFile("res/pl.png");
	sprite.setTexture(texture);
	rect = FloatRect(25, 25, textLenght, textHeight);
	exist = true;
	isPhysical = true;
	alive = true;
	countOfFrames = 5;
	dx = 0;
	dy = 0;
	speed = 0.1;
	buffer.resize(2);
	loadSound(jump, "res/jump.wav");
	loadSound(hit, "res/hit.wav");
	loadSound(damage, "res/damage.wav");
	loadSound(speedup, "res/speedup.wav");
}

bool Player::update(double time, sf::RenderWindow& window, IMap* map)
{
	bool result = false;
	if (HP == 0)
	{
		alive = false;
		kill();
		if (deathTimer.getElapsedTime().asSeconds() > 5)
		{
			std::cout << "Timer worked\n";
			result = true;
		}
	}
	if (alive)
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
				std::cout << "x = " << rect.left << " y = " << rect.top << std::endl;
				playSound(jump);
				dy = -0.30;
				onGround = false;
			}
		}

	}
	if (damageTimer.getElapsedTime().asMilliseconds() > 500)
	{
		damaged = false;
	}
	if ((speedTimer.getElapsedTime().asSeconds() > 3) && (bonusMask & BonusFilter::speed))
	{
		bonusMask = bonusMask ^ BonusFilter::speed;
		this->speed = 0.1;
	}

	rect.left += dx * time;
	map->collisionX(*this);

	if (!onGround) dy = dy + 0.0005 * time;
	rect.top += dy * time;
	onGround = false;
	map->collisionY(*this);

	curFrame += 0.003 * time;

	if (alive)
	{
		if (curFrame > 3) curFrame = 0;
		if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
		if (dx < 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)), 0, textLenght, textHeight));
		if (dx > 0) sprite.setTextureRect(IntRect(textLenght + (textLenght * int(curFrame)) + textLenght, 0, -textLenght, textHeight));
		if (dy < 0 && onGround == false) sprite.setTextureRect(IntRect(textLenght * (countOfFrames - 1), 0, textLenght, textHeight));
		if (dy < 0 && onGround == false && Keyboard::isKeyPressed(Keyboard::Right)) sprite.setTextureRect(IntRect(textLenght * countOfFrames, 0, -textLenght, textHeight));
	}
	sprite.setPosition(rect.left - map->getOfSetX(), rect.top - map->getOfSetY());

	dx = 0;
	window.draw(sprite);
	return result;
}

bool Player::checkFights(IEnemy& en)
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
			HP--;
			playSound(damage);
			dy -= 0.3;
			return false;
		}
	}

}

bool Player::checkFights(IBoss& en)
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
			HP--;
			playSound(damage);
			dy -= 0.3;
			return false;
		}
	}

}

bool Player::checkBonus(IBonus& bonus)
{
	if (rect.intersects(bonus.getRect()))
	{
		bonusMask = bonusMask | bonus.peekBonus();
		if (bonusMask & BonusFilter::hp)
		{
			HP++;
			bonus.getBonus();
			bonusMask ^= BonusFilter::hp;
		}
		if (bonusMask & BonusFilter::speed)
		{
			if (speed != 0.15)
			{
				speedTimer.restart();
				speedTimer.getElapsedTime();
				speed = 0.15;
				bonus.getBonus();
				playSound(speedup);
			}
			// bonusMask ^= BonusFilter::speed;
		}
	}
	return true;
}

void Player::getDamage()
{
	HP--;
}

uint16_t Player::getHealth()
{
	return HP;
}

uint16_t Player::getBonus()
{
	return bonusMask;
}

bool Player::getStatus()
{
	return alive;
}

void Player::kill()
{

	sprite.setTextureRect(IntRect(0, 0, textLenght, textHeight));
	if (exist)
	{
		sprite.rotate(90);
		deathTimer.restart();
	}
	exist = false;
}