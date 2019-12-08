#pragma once
#include "Map.h"
#include "Player.h"
class Game
{
public:
	Game();
	Player pl;
	Map map;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	sf::Clock clock;
	double time = 0;
	sf::RenderWindow window;
	void start();
};

