#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MapGenerator
{
protected:
	uint16_t W = 73, H = 18, sb = 20;
	sf::Sprite groundSprite;
	sf::Texture groundTexture;
	const uint16_t countOfParts = 4;
	/*std::vector<std::string> map =
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
	};*/
	std::vector<std::string> map;

	void generate();
};