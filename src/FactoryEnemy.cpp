#include "FactoryEnemy.h"

std::vector<IEnemy*> FactoryEnemy::enemies;

IEnemy* FactoryEnemy::createTurtle()
{
	IEnemy* temp = new Turtle;
	enemies.push_back(temp);
	return temp;
}

IEnemy* FactoryEnemy::createTurtle(double x, double y)
{
	IEnemy* temp = new Turtle;
	enemies.push_back(temp);
	temp->setCoords(x, y);
	return temp;
}

void FactoryEnemy::destroyEnemy(size_t index)
{
	enemies.erase(enemies.begin() + index);
}

void FactoryEnemy::destroyAllEnemies()
{
	enemies.resize(0);
}

IEnemy* FactoryEnemy::getEnemy(size_t index)
{
	return enemies[index];
}

size_t FactoryEnemy::getSize()
{
	return enemies.size();
}


