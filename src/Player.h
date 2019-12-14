#pragma once
#include "BaseUnit.h"
#include "IMap.h"
#include "IEnemy.h"

class Player : public BaseUnit 
{
public:
	Player();
	double ofsetX = 0;
	double ofsetY = 0;
	uint16_t HP = 3;
	void update(double time, sf::RenderWindow &window,IMap * map);
	bool checkFights(IEnemy & en);
	void getDamage();
	
	
};

