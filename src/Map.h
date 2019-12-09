#pragma once
#include "Player.h"
#include "IMap.h"
class Map : public IMap
{
public:
	Map();
	const int W = 73, H = 18, sb = 20;
	Sprite groundSprite;
	Texture groundTexture;
	float ofsetX = 0, ofsetY = 0;
	
	std::vector<std::string> map = 
	{
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                   BBBB     BBBBBBBBBBBBBBBBBBBB      B",
	"B                                  BBBBB                               B",
	"BBBB                              BBBBBB                               B",
	"B                                BBBBBBB                               B",
	"B                               BBBBBBBB                               B",
	"B                              BBBBBBBBB                               B",
	"B                             BBBBBBBBBB                               B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	bool update(sf::RenderWindow &window, BaseUnit &pl) override;
	bool collisionX(BaseUnit& unit) override;
	bool collisionY(BaseUnit& unit) override;
	double getOfSetX() override;
	double getOfSetY() override;

	//bool collision(BaseUnit &unit);
	//~Map() = default;
};

