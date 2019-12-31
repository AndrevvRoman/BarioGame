#pragma once
#include "BaseUnit.h"
class IMap
{
public:
	virtual bool collisionX(BaseUnit& unit) = 0;
	virtual bool collisionY(BaseUnit& unit) = 0;
	virtual bool update(sf::RenderWindow& window, BaseUnit& pl) = 0;
	virtual double getOfSetX() = 0;
	virtual double getOfSetY() = 0;
	virtual void generateMap() = 0;
	virtual sf::Vector2f getEdgeCoords() = 0;
	~IMap() = default;
};

