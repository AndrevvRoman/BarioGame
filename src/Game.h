#pragma once
#include "Player.h"
#include "IEnemy.h"
#include <list>
class Game
{
public:
	Game();
	Player pl;
	std::vector<IEnemy*> enemies;
	IMap * map = nullptr;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	sf::Clock clock;
	double time = 0;
	sf::RenderWindow window;
	void start();
	~Game();
};