#pragma once
#include "IMap.h"

enum BonusFilter
{
	speed = 0x1,
	hp = 0x2,
};

class IBonus
{
public:

	virtual uint16_t getBonus() = 0;
	virtual bool getStatus() = 0;
	virtual sf::FloatRect getRect() = 0;
	virtual bool update(double time, sf::RenderWindow& window, IMap* map) = 0;
	~IBonus() = default;
};

