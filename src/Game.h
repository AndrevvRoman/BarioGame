#pragma once
#include "Player.h"
#include "IEnemy.h"
#include "IBonus.h"
#include "GUI.h"
#include <list>
class Game : public GUI
{
public:
	Game();
	Player pl;
	uint16_t score = 0;
	std::vector<IEnemy*> enemies;
	std::vector<IBonus*> bonuses;
	IMap * map = nullptr;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	sf::Clock clock;
	double time = 0;
	sf::RenderWindow window;
	void start();
	void updatePlayer();
	void updateEnemies();
	void updateBonuses();
	void checkBonuses();
	void checkFights();
	void updateMap();
	~Game();
};