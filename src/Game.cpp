#include <iostream>
#include "Game.h"
#include "Map.h"
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
	clock.restart();
	map = new Map;
	srand(std::time(NULL));
	size_t N = rand() % 5 + 1;
	for (size_t i = 0; i < N; i++)
	{
		FactoryEnemy::createTurtle();
	}

	N = rand() % 2 + 1;
	for (size_t i = 0; i < N; i++)
	{
		FactoryBonus::createMushroom();
	}

	boss = new Buzzer;
	boss->setCoords(static_cast<double>(map->getEdgeCoords().x) - 300, static_cast<double>(map->getEdgeCoords().y) - 100);

}

void Game::start()
{

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			if (!menu())
			{
				setHighScore(score);
				exit(EXIT_SUCCESS);	
			}
			
		}
		
		window.clear();
		window.draw(backGroundSprite);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				setHighScore(score);
				window.close();
			}
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
	for (size_t i = 0; i < FactoryEnemy::getSize(); i++)
	{
		if (FactoryEnemy::getEnemy(i)->update(time, window, map))
		{
			score += 100;
			FactoryEnemy::destroyEnemy(i);
			//enemies.erase(enemies.begin() + i);
			std::cout << "deleted\n";
		}
	}
	if ( boss != nullptr && boss->update(time, window, map))
	{
		nextLevelTimer.restart();
		nextLevelTimer.getElapsedTime();
		score += 1000;
		delete boss;
		boss = nullptr;
	}
}

void Game::updateBonuses()
{
	for (size_t i = 0; i < FactoryBonus::getSize(); i++)
	{
		if (!FactoryBonus::getBonus(i)->update(time, window, map))
		{
			FactoryBonus::destroyBonus(i);
		}
	}
}

void Game::checkBonuses()
{
	if (pl.getStatus())
	{
		for (size_t i = 0; i < FactoryBonus::getSize(); i++)
		{
			pl.checkBonus(*FactoryBonus::getBonus(i));
		}
	}
}

void Game::checkFights()
{
	if (pl.getStatus())
	{
		for (size_t i = 0; i < FactoryEnemy::getSize(); i++)
			pl.checkFights(*FactoryEnemy::getEnemy(i));
		if (boss != nullptr)
		{
			pl.checkFights(*boss);
		}
	}
}



void Game::updateMap()
{
	if (map->update(window, pl) && boss == nullptr && nextLevelTimer.getElapsedTime().asSeconds() > 10)
	{

		FactoryEnemy::destroyAllEnemies();
		size_t N = rand() % 5 + 1;

		FactoryBonus::destroyAllBonuses();

		for (size_t i = 0; i < N; i++)
		{
			FactoryEnemy::createTurtle();
		}

		N = rand() % 2 + 1;
		for (size_t i = 0; i < N; i++)
		{
			FactoryBonus::createMushroom();
		}

		boss = new Buzzer;
		boss->setCoords(static_cast<double>(map->getEdgeCoords().x) - 300, static_cast<double>(map->getEdgeCoords().y) - 100);
		pl.setRect(50,50);
		map->generateMap();
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

		if (Keyboard::isKeyPressed(Keyboard::Space) && (animTimer.getElapsedTime().asMilliseconds() > 300))
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
	FactoryEnemy::destroyAllEnemies();
	FactoryBonus::destroyAllBonuses();
	if (boss != nullptr)
		delete boss;
	delete map;
}
