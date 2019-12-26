#pragma once
#include "BaseUnit.h"
#include "IMap.h"
#include "IEnemy.h"
#include "IBonus.h"
#include "Sound.h"

class Player : public BaseUnit, public Sound
{
public:
	Player();
	double ofsetX = 0;
	double ofsetY = 0;
	uint16_t bonusMask = 0;
	void update(double time, sf::RenderWindow &window,IMap * map);
	bool checkFights(IEnemy & en);
	bool checkBonus(IBonus& bonus);
	void getDamage();
	uint16_t getHealth(); 
	bool getStatus();
private:
	void kill();
	uint16_t HP = 3;
};

