#include "Map.h"
#include <iostream>

Map::Map()
{
	generate();
	groundTexture.loadFromFile("res/ground.png");
	groundSprite.setTexture(groundTexture);
}

bool Map::update(sf::RenderWindow& window, BaseUnit& pl)
{
	FloatRect temp = pl.getRect();

	if (pl.getRect().top > window.getSize().x / 2) ofsetY = temp.top - static_cast<float>(window.getSize().x / 3);
	if (pl.getRect().left > window.getSize().y / 2) ofsetX = temp.left - static_cast<float>(window.getSize().y / 2);

	

	pl.setRect(temp);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 'B') 
			{ 
				groundSprite.setPosition(sb * j - ofsetX, sb * i - ofsetY);
				window.draw(groundSprite);
			}
		}
	}
	sf::FloatRect rect = pl.getRect();
	if (rect.left > 700)
	{
		rect.left = 0;
		rect.top = 10;
		pl.setRect(temp);
		generate();
	}

	
	return true;
}

bool Map::collisionX(BaseUnit& unit)
{
	bool collised = false;
	sf::FloatRect rect = unit.getRect();
	for (int i = rect.top / sb; i < ((((rect.top + rect.height) / sb) < 18 ? ((rect.top + rect.height) / sb) : 18)); i++)
	{
		for (int j = rect.left / sb; j < (rect.left + rect.width) / sb; j++)
		{
			if (map[i][j] == 'B')
			{
				if (unit.dx > 0)
				{
					rect.left = j * sb - rect.width;
					unit.setRect(rect);
					collised = true;
				}
				if (unit.dx < 0)
				{
					rect.left = j * sb + sb;
					unit.setRect(rect);
					collised = true;
				}
			}
		}
	}
	return collised;
}

bool Map::collisionY(BaseUnit& unit)
{
	bool collised = false;
	sf::FloatRect rect = unit.getRect();
	for (int i = rect.top / sb; i < (( ((rect.top + rect.height) / sb) < 18 ? ((rect.top + rect.height) / sb) : 18)); i++)
	{
		for (int j = rect.left / sb; j < (rect.left + rect.width) / sb; j++)
		{
			//std::cout << "i = " << i << " j = " << j << std::endl;
			if (map[i][j] == 'B')
			{
				if (unit.dy > 0)
				{
					rect.top = i * sb - rect.height;
					unit.dy = 0;
					unit.setRect(rect);
					unit.onGround = true;
				}
				if (unit.dy < 0)
				{
					rect.top = i * sb + sb;
					unit.setRect(rect);
					unit.dy = 0;
				}
			}
		}
	}
	return collised;
}

double Map::getOfSetX()
{
	return ofsetX;
}

double Map::getOfSetY()
{
	return ofsetY;
}

