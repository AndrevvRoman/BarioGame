#pragma once
class IMap
{
public:
	virtual bool collisionX(BaseUnit& unit) = 0;
	virtual bool collisionY(BaseUnit& unit) = 0;
	virtual bool update(sf::RenderWindow& window, BaseUnit& pl) = 0;
	virtual double getOfSetX() = 0;
	virtual double getOfSetY() = 0;
	//~IMap() = default;
};

