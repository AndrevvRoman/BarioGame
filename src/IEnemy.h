#pragma once
#include "IMap.h"
class IEnemy
{
public:
	virtual void update(double time, sf::RenderWindow& window, IMap * map) = 0;
	virtual void getDamage() = 0;
	virtual sf::FloatRect getRect() = 0;
	~IEnemy() = default;
};