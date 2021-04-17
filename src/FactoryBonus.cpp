#include "FactoryBonus.h"
#include <iostream>
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

IBonus* FactoryBonus::createFlower()
{
	IBonus* temp = new Flower;
	bonuses.push_back(temp);

	return temp;
}

IBonus* FactoryBonus::createFlower(double x, double y)
{
	IBonus* temp = new Flower;
	bonuses.push_back(temp);

	return temp;
}

void FactoryBonus::createBonus()
{
	uint16_t count = (rand() % 6) + 1;
	std::cout << "count^ " << count << std::endl;
	for (size_t i = 0; i < count; i++)
	{
		uint16_t N = rand() % 2;
		switch (N)
		{
		case 0:
		{
			FactoryBonus::createFlower();
			break;
		}
		case 1:
		{
			FactoryBonus::createMushroom();
			break;
		}
		default:
			break;
		}
	}
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
