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
	std::vector<std::string> map;

	void generate();
private:
	void mergePart(const std::string & temp, std::size_t & j);
};