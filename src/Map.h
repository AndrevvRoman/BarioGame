#pragma once
#include <vector>
#include "Player.h"
#include "MapGenerator.h"

class Map : public IMap , protected MapGenerator
{
public:
	Map();
	double ofsetX = 0, ofsetY = 0;
	bool update(sf::RenderWindow &window, BaseUnit &pl) override;
	bool collisionX(BaseUnit& unit) override;
	bool collisionY(BaseUnit& unit) override;
	double getOfSetX() override;
	double getOfSetY() override;
	sf::Vector2f getEdgeCoords() override;
	~Map() = default;
};

