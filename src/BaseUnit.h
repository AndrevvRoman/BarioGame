#pragma once
#include <SFML/Graphics.hpp>


using sf::Texture;
using sf::FloatRect;
using sf::Sprite;
using sf::IntRect;
using sf::Keyboard;

class BaseUnit
{
public:
	BaseUnit();
	FloatRect getRect() const;
	void setRect(sf::FloatRect temp);
	double dx = 0.1;
	double dy = 0.1;
	bool onGround = false;
	bool damaged = false;
	Sprite sprite;
	sf::Clock damageTimer;
protected:
	float speed = 0;
	int textLenght = 0;
	int textHeight = 0;
	uint16_t countOfFrames = 0;
	FloatRect rect;
	Texture texture;
	bool exist = false;
	bool alive = false;
	double curFrame = 0;
	bool isPhysical = true;
};

