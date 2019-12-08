#include "BaseUnit.h"

BaseUnit::BaseUnit()
{

}

FloatRect BaseUnit::getRect() const
{
	return rect;
}

void BaseUnit::setRect(sf::FloatRect temp)
{
	rect = temp;
}




