#pragma once
#include "BaseUnit.h"
#include "IMap.h"
#include "IEnemy.h"
#include "IBonus.h"
#include "IBoss.h"
#include "Sound.h"

class Player : public BaseUnit, public Sound
{
public:
	Player();
	double ofsetX = 0;
	double ofsetY = 0;
	uint16_t bonusMask = 0;
	bool update(double time, sf::RenderWindow &window,IMap * map);
	bool checkFights(IEnemy & en);
	bool checkFights(IBoss& en);
	bool checkBonus(IBonus& bonus);
	void getDamage();
	uint16_t getHealth(); 
	uint16_t getBonus();
	bool getStatus();
	uint16_t HP = 3;
private:
	void kill();
	
	sf::Clock deathTimer;
	sf::Clock speedTimer;
};

