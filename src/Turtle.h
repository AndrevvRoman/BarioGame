#pragma once
#include "IEnemy.h"
#include "BaseUnit.h"
class Turtle : public IEnemy , public BaseUnit
{
public:
	Turtle();
	bool dir = false;
	int HP = 3;
	bool update(double time, sf::RenderWindow& window, IMap * map) override;
	void getDamage() override;
	sf::FloatRect getRect() override;
	bool getStatus() override;
private:
	void kill();
};