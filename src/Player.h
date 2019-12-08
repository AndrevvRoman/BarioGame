#pragma once
#include "BaseUnit.h"

class Player : public BaseUnit 
{
public:
	
	Player();
	uint16_t HP = 3;
	void update(double time, sf::RenderWindow &window) override;
};

