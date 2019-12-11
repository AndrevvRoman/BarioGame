#include "BaseUnit.h"

BaseUnit::BaseUnit()
{

}

sf::FloatRect BaseUnit::getRect() const
{
	return rect;
}

void BaseUnit::setRect(sf::FloatRect temp)
{
	rect = temp;
}




