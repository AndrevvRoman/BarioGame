#pragma once
#include "IBoss.h"
#include "BaseUnit.h"
class Buzzer : public IBoss, public BaseUnit
{
public:
	Buzzer();
	bool getStatus() override;
	bool update(double time, sf::RenderWindow& window, IMap* map) override;
	void getDamage() override;
	sf::FloatRect getRect() override;
	void getReward() override;
	void setCoords(double x, double y) override;
	~Buzzer() = default;
private:
	bool spotted = false;
	uint16_t HP = 1;
	bool dir = false;
	void kill();
};

