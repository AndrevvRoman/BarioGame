#pragma once
#include <SFML/Graphics.hpp>
class GUI
{
public:
	GUI();
	void updateGUI(sf::RenderWindow& window, uint16_t hp, uint16_t score,uint16_t bonusMask);
	void drawMenu(sf::RenderWindow& window, int choosen);
	void setMenu(sf::RenderWindow& window);
	size_t getStringCount();
	void setHighScore(uint16_t);
	~GUI() = default;
private:
	sf::Text speedUpText;
	uint16_t getHighScore();
	sf::Text healthText;
	sf::Text scoreText;
	sf::Text scoreCount;
	sf::Text healthCount;
	std::vector<sf::Text> menuText;
	sf::Text highScore;
	sf::Font font;
	std::vector<sf::RectangleShape> menu;
};