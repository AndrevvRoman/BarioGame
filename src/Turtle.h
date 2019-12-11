#pragma once
#include "IEnemy.h"
#include "BaseUnit.h"
class Turtle : public IEnemy , public BaseUnit
{
public:
	bool dir = false;
	int HP = 2;
	Turtle();
	void update(double time, sf::RenderWindow& window, IMap * map) override;
	void getDamage() override;
	sf::FloatRect getRect() override;
private:
	void kill();
};