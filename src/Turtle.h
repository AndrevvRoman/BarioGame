#pragma once
#include "IEnemy.h"
#include "BaseUnit.h"
class Turtle : public IEnemy , public BaseUnit
{
public:
	Turtle();


	bool update(double time, sf::RenderWindow& window, IMap * map) override;
	void getDamage() override;
	sf::FloatRect getRect() override;
	bool getStatus() override;
	void setCoords(double x, double y) override;
	~Turtle() = default;
private:
	uint16_t HP = 3;
	bool dir = false;
	void kill();
};