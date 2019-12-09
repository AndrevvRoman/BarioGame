#pragma once
#include "Map.h"
class Game
{
public:
	Game();
	Player pl;
	IMap * map = nullptr;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	sf::Clock clock;
	double time = 0;
	sf::RenderWindow window;
	void start();
	//~Game() = default;
};