#pragma once
#include "IEnemy.h"
#include "BaseUnit.h"
class Turtle : public IEnemy , BaseUnit
{
public:
	bool dir = false;
	Turtle();
	void update(double time, sf::RenderWindow& window, IMap * map) override;
	void getDamage() override;
	void sendDamage() override;
};