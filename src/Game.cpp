#include <iostream>
#include "Game.h"
#include "Map.h"
#include "Turtle.h"
#include "Mushroom.h"
#include "Buzzer.h"
#include <ctime>
#include <cstdlib>

Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Bario");
	backGroundTexture.loadFromFile("res/backgrnd.png");
	backGroundSprite.setTexture(backGroundTexture);
	if (!menu())
	{
		exit(EXIT_SUCCESS);
	}

	map = new Map;
	srand(std::time(NULL));
	enemies.resize(rand() % 5 + 1);
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i] = new Turtle;
	}

	bonuses.resize(rand() % 2 + 1);
	for (size_t i = 0; i < bonuses.size(); i++)
	{
		bonuses[i] = new Mushroom;
	}

	boss = new Buzzer;
	boss->setCoords(map->getEdgeCoords().x - 300, map->getEdgeCoords().y - 100);

}

void Game::start()
{

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			if (!menu())
			{
				exit(EXIT_SUCCESS);
				
			}
			
		}
		
		//clock.restart();
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
		if (updatePlayer())
			return;
		updateEnemies();
		updateBonuses();
		checkFights();
		checkBonuses();
		updateMap();
		updateGUI(window, pl.getHealth(), score);
		
		window.display();

	}
}

bool Game::updatePlayer()
{
	if (pl.update(time, window, map))
	{
		
		setHighScore(score);
		return true;
	}
	return false;
}

void Game::updateEnemies()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->update(time, window, map))
		{
			score += 100;
			enemies.erase(enemies.begin() + i);
			std::cout << "deleted\n";
		}
	}
	if (boss->update(time, window, map))
	{
		score += 1000;
		delete boss;
	}
}

void Game::updateBonuses()
{
	for (size_t i = 0; i < bonuses.size(); i++)
	{
		
		if (!bonuses[i]->update(time, window, map))
		{
			bonuses.erase(bonuses.begin() + i);
		}
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
		pl.checkFights(*boss);
	}
}



void Game::updateMap()
{
	if (map->update(window, pl))
	{
		enemies.resize(0);
		enemies.resize(rand() % 5 + 1);

		bonuses.resize(0);
		bonuses.resize(rand() % 2 + 1);

		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i] = new Turtle;
		}

		for (size_t i = 0; i < bonuses.size(); i++)
		{
			bonuses[i] = new Mushroom;
		}

	}
}

bool Game::menu()
{
	sf::Clock animTimer;
	int choose = 0;
	setMenu(window);
	animTimer.restart();
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
		if (Keyboard::isKeyPressed(Keyboard::Down) && (animTimer.getElapsedTime().asMilliseconds() > 300))
		{
			choose++;
			if (choose >= getStringCount())
				choose = 0;
			animTimer.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && (animTimer.getElapsedTime().asMilliseconds() > 300))
		{
			choose--;
			if (choose < 0)
				choose = getStringCount() - 1;
			animTimer.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter) && (animTimer.getElapsedTime().asMilliseconds() > 300))
		{
			if (choose == 0)
				return true;
			else
				return false;
		}


		drawMenu(window, choose);
		
		window.display();

	}
	return false;
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
