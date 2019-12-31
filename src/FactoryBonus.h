#pragma once
#include "IBonus.h"
#include "Mushroom.h"
class FactoryBonus
{
public:
	FactoryBonus() = default;
	static IBonus* createMushroom();
	static IBonus* createMushroom(double x, double y);
	static void destroyBonus(size_t index);
	static void destroyAllBonuses();
	static IBonus* getBonus(size_t index);
	static size_t getSize();
private:
	static std::vector<IBonus*> bonuses;
};

