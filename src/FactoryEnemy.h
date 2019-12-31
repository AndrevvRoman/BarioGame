#pragma once
#include "IEnemy.h"
#include "Turtle.h"
class FactoryEnemy
{
public:
	FactoryEnemy() = default;
	static IEnemy* createTurtle();
	static IEnemy* createTurtle(double x, double y);
	static void destroyEnemy(size_t index);
	static void destroyAllEnemies();
	static IEnemy* getEnemy(size_t index);
	static size_t getSize();
private:
	static std::vector<IEnemy*> enemies;
};



