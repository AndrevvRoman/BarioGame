#include "GUI.h"
#include <iostream>
GUI::GUI()
{
	font.loadFromFile("res/font.ttf");

	scoreText.setPosition(sf::Vector2f(20, 10));
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setCharacterSize(40);
	scoreText.setString("score");

	scoreCount.setPosition(sf::Vector2f(20, 30));
	scoreCount.setFont(font);
	scoreCount.setFillColor(sf::Color::Black);
	scoreCount.setCharacterSize(40);

	healthText.setPosition(sf::Vector2f(200, 10));
	healthText.setFont(font);
	healthText.setFillColor(sf::Color::Black);
	healthText.setCharacterSize(40);
	healthText.setString("health");

	healthCount.setPosition(sf::Vector2f(200, 30));
	healthCount.setFont(font);
	healthCount.setFillColor(sf::Color::Black);
	healthCount.setCharacterSize(40);
}

void GUI::updateGUI(sf::RenderWindow& window, uint16_t hp, uint16_t score)
{
	window.draw(healthText);
	window.draw(scoreText);
	auto s1 = std::to_string(hp);
	healthCount.setString(s1);
	window.draw(healthCount);
	auto s2 = std::to_string(score);
	scoreCount.setString(s2);
	window.draw(scoreCount);
}
