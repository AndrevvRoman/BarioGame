#include "Game.h"
#include <iostream>
Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Bario");
	backGroundTexture.loadFromFile("res/backgrnd.png");
	backGroundSprite.setTexture(backGroundTexture);
	map = new Map;
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
		map->update(window, pl);
		window.display();

	}
}
