#pragma once
#include "Player.h"
#include "IBonus.h"
#include "FactoryBonus.h"
#include "GUI.h"
#include "FactoryEnemy.h"

class Game : public GUI
{
public:
	Game();
	void start();
	~Game();
private:
	Player pl;
	uint16_t score = 0;
	IBoss* boss = nullptr;
	IMap* map = nullptr;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	sf::Clock clock;
	sf::Clock nextLevelTimer;
	double time = 0;
	sf::RenderWindow window;

	bool updatePlayer();
	void updateEnemies();
	void updateBonuses();
	void checkBonuses();
	void checkFights();
	void updateMap();
	bool menu();
	
};