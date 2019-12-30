#pragma once
#include "IMap.h"
class IBoss
{
public:
	virtual bool getStatus() = 0;
	virtual bool update(double time, sf::RenderWindow& window, IMap* map) = 0;
	virtual void getDamage() = 0;
	virtual sf::FloatRect getRect() = 0;
	virtual void setCoords(double x, double y) = 0;
	virtual void getReward() = 0;
	~IBoss() = default;
};

