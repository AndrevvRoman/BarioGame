#include "GUI.h"
#include <iostream>
#include <fstream>
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

void GUI::setMenu(sf::RenderWindow& window)
{
	menu.resize(2);
	menuText.resize(3);
	for (size_t i = 0; i < menu.size(); i++)
	{
		menuText[i].setFont(font);
		menu[i].setSize(sf::Vector2f(300, 50));
		menuText[i].setCharacterSize(30);
		menu[i].setPosition((window.getSize().x / 2) - (menu[i].getSize().x / 2), ((window.getSize().y / 2) + i * 1.5 * menu[i].getSize().y) - (menu[i].getSize().y / 2));
		menuText[i].setPosition(sf::Vector2f(menu[i].getPosition().x, menu[i].getPosition().y));
		menu[i].setFillColor(sf::Color::Black);
		menuText[i].setFillColor(sf::Color::Yellow);
	}
	menuText[0].setString("play");
	menuText[1].setString("exit");

	menuText[2].setFont(font);
	menuText[2].setCharacterSize(40);
	menuText[2].setPosition(menu[0].getPosition().x, menu[0].getPosition().y - 1.5 * menu[0].getSize().y);
	menuText[2].setFillColor(sf::Color::Black);
	menuText[2].setString("high score");

	
	highScore.setFont(font);
	highScore.setCharacterSize(40);
	highScore.setPosition(menu[0].getPosition().x + menuText[2].getCharacterSize() * 5, menu[0].getPosition().y - 1.5 * menu[0].getSize().y);
	highScore.setFillColor(sf::Color::Black);
	auto s = std::to_string(getHighScore());
	highScore.setString(s);
}

size_t GUI::getStringCount()
{
	return menu.size();
}

uint16_t GUI::getHighScore()
{
	uint16_t score = 0;
	std::ifstream in;
	in.open("C:\\Users\\Public\\Documents\\save.txt",std::ios::in);
	if (!in.is_open())
	{
		std::cout << "No save file. Creating..\n";
		std::ofstream out;
		out.open("C:\\Users\\Public\\Documents\\save.txt", std::ios::out);
		out << 0;
		std::cout << "Done\n";
		out.close();
	}
	else
	{
		in >> score;
		in.close();
		std::cout << score << std::endl;
	}
	return score;
}

void GUI::setHighScore(uint16_t curScore)
{

	std::ifstream in;
	in.open("C:\\Users\\Public\\Documents\\save.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cout << "in FileEr\n";
	}
	uint16_t score;
	in >> score;
	in.close();
	if (curScore > score)
	{
		std::ofstream out;
		out.open("C:\\Users\\Public\\Documents\\save.txt", std::ios::out);
		if (!out.is_open())
		{
			std::cout << "out FileEr\n";
		}

		out << curScore;
		out.close();
	}

}

void GUI::drawMenu(sf::RenderWindow& window, int choosen)
{
	for (size_t i = 0; i < menu.size(); i++)
	{
		menu[i].setFillColor(sf::Color::Black);
		menuText[i].setFillColor(sf::Color::Yellow);
		if (i == choosen)
		{
			menu[i].setFillColor(sf::Color::Yellow);
			menuText[i].setFillColor(sf::Color::Black);
		}
		
		window.draw(menu[i]);
		window.draw(menuText[i]);
	}
	window.draw(menuText[2]);
	window.draw(highScore);
}
