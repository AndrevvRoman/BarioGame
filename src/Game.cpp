#include <iostream>
#include "Game.h"
#include "Map.h"
#include "Turtle.h"
#include "Mushroom.h"
#include <ctime>

Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Bario");
	backGroundTexture.loadFromFile("res/backgrnd.png");
	backGroundSprite.setTexture(backGroundTexture);
	map = new Map;
	srand(std::time(NULL));
	enemies.resize(rand() % 5 + 1);
	std::cout << "enem size = " << enemies.size() << std::endl;
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i] = new Turtle;
	}

	bonuses.resize(1);
	for (size_t i = 0; i < bonuses.size(); i++)
	{
		bonuses[i] = new Mushroom;
	}
}

void Game::start()
{

	while (window.isOpen())
	{
		window.clear();
		window.draw(backGroundSprite);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		updatePlayer();
		updateEnemies();
		updateBonuses();
		checkFights();
		checkBonuses();
		updateMap();

		updateGUI(window, pl.getHealth(), score);
		
		window.display();

	}
}

void Game::updatePlayer()
{
	pl.update(time, window, map);
}

void Game::updateEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->update(time, window, map))
		{
			score += 100;
			enemies.erase(enemies.begin() + i);
		}
	}
}

void Game::updateBonuses()
{
	for (size_t i = 0; i < bonuses.size(); i++)
	{
		bonuses[i]->update(time, window, map);
	}
}

void Game::checkBonuses()
{
	if (pl.getStatus())
	{
		for (size_t i = 0; i < bonuses.size(); i++)
		{
			pl.checkBonus(*bonuses[i]);
		}
	}
}

void Game::checkFights()
{
	if (pl.getStatus())
	{
		for (int i = 0; i < enemies.size(); i++)
			pl.checkFights(*enemies[i]);
	}
}



void Game::updateMap()
{
	srand(std::time(NULL));
	if (map->update(window, pl))
	{
		enemies.resize(0);
		enemies.resize(rand() % 5);
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i] = new Turtle;
		}
	}
}

Game::~Game()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}
	for (size_t i = 0; i < bonuses.size(); i++)
	{
		delete bonuses[i];
	}
	delete map;
}
