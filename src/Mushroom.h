#pragma once
#include "IBonus.h"
#include "BaseUnit.h"
class Mushroom : public BaseUnit, public IBonus 
{
public:
	Mushroom();
	bool update(double time, sf::RenderWindow& window, IMap* map) override;
	uint16_t getBonus() override;
	bool getStatus() override;
	uint16_t peekBonus() override;
	sf::FloatRect getRect() override;
};

