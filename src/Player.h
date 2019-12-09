#pragma once
#include "BaseUnit.h"
#include "IMap.h"
class Player : public BaseUnit 
{
public:
	double ofsetX = 0;
	double ofsetY = 0;
	Player();
	uint16_t HP = 3;
	void update(double time, sf::RenderWindow &window,IMap * map);
};

