#include "BaseUnit.h"

BaseUnit::BaseUnit()
{

}

sf::FloatRect BaseUnit::getRect() const
{
	return rect;
}

void BaseUnit::setRect(const sf::FloatRect & temp)
{
	rect = temp;
}

void BaseUnit::setRect(const double x, const double y)
{
	rect.left = x;
	rect.top = y;
}




