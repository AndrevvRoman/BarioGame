#include <iostream>
#include "Game.h"
#include "Map.h"
#include "Turtle.h"

Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Bario");
	backGroundTexture.loadFromFile("res/backgrnd.png");
	backGroundSprite.setTexture(backGroundTexture);
	map = new Map;
	enemies.resize(2);
	for (int i = 0; i < 2; i++)
	{
		enemies[i] = new Turtle;
	}
}

void Game::start()
{
	while (window.isOpen())
	{
		window.clear();
		window.draw(backGroundSprite);
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		pl.update(time,window,map);
		for (int i = 0; i < enemies.size(); i++)
			enemies[i]->update(time, window, map);
		for (int i = 0; i < enemies.size(); i++)
			pl.checkFights(*enemies[i]);

		map->update(window, pl);
		
		window.display();

	}
}

Game::~Game()
{
	delete map;
}
