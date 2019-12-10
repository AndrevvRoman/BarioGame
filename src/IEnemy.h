#pragma once
#include "IMap.h"
class IEnemy
{
public:
	virtual void update(double time, sf::RenderWindow& window, IMap * map) = 0;
	virtual void getDamage() = 0;
	virtual void sendDamage() = 0;
	~IEnemy() = default;
};