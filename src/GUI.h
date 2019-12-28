#pragma once
#include <SFML/Graphics.hpp>
class GUI
{
public:
	GUI();
	void updateGUI(sf::RenderWindow& window, uint16_t hp, uint16_t score);
	void drawMenu(sf::RenderWindow& window, int choosen);
	void setMenu(sf::RenderWindow& window);
	size_t getStringCount();
	~GUI() = default;
private:
	sf::Text healthText;
	sf::Text scoreText;
	sf::Text scoreCount;
	sf::Text healthCount;
	std::vector<sf::Text> menuText;
	sf::Font font;
	std::vector<sf::RectangleShape> menu;
};