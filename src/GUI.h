#pragma once
#include <SFML/Graphics.hpp>
class GUI
{
public:
	GUI();
	sf::Text healthText;
	sf::Text scoreText;
	sf::Text scoreCount;
	sf::Text healthCount;
	sf::Font font;

	void updateGUI(sf::RenderWindow& window, uint16_t hp, uint16_t score);
};