#include "FactoryBonus.h"

std::vector<IBonus*> FactoryBonus::bonuses;

IBonus* FactoryBonus::createMushroom()
{
	IBonus * temp = new Mushroom;
	bonuses.push_back(temp);
	return temp;
}

/*TODO*/
//setCoord bonus
IBonus* FactoryBonus::createMushroom(double x, double y)
{
	IBonus* temp = new Mushroom;
	bonuses.push_back(temp);

	return temp;
}

void FactoryBonus::destroyBonus(size_t index)
{
	bonuses.erase(bonuses.begin() + index);
}

void FactoryBonus::destroyAllBonuses()
{
	bonuses.resize(0);
}

IBonus* FactoryBonus::getBonus(size_t index)
{
	return bonuses[index];
}

size_t FactoryBonus::getSize()
{
	return bonuses.size();
}
