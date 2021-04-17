#pragma once
#include "IBonus.h"
#include "Mushroom.h"
#include "Flower.h"
class FactoryBonus
{
public:
	FactoryBonus() = default;
	static IBonus* createMushroom();
	static IBonus* createMushroom(double x, double y);
	static IBonus* createFlower();
	static IBonus* createFlower(double x, double y);
	static void createBonus();
	static void destroyBonus(size_t index);
	static void destroyAllBonuses();
	static IBonus* getBonus(size_t index);
	static size_t getSize();
private:
	static std::vector<IBonus*> bonuses;
};

