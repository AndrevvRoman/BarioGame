#include "Map.h"
#include <iostream>

Map::Map()
{
	groundTexture.loadFromFile("res/ground.png");
	groundSprite.setTexture(groundTexture);
}

void Map::update(sf::RenderWindow& window, BaseUnit& unit)
{
	if (unit.getRect().top > 640 / 3) ofsetY = unit.getRect().top - 640 / 3;
	if (unit.getRect().left > 480 / 3) ofsetX = unit.getRect().left - 480 / 3;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == 'B') 
			{ 
				groundSprite.setPosition(sb * j - ofsetX, sb * i - ofsetY); 
				window.draw(groundSprite);
			}
		}
	}

	collision(unit);
	window.draw(unit.sprite);
}

bool Map::collision(BaseUnit &unit)
{
	bool collised = false;
	sf::FloatRect rect = unit.getRect();
	for (int i = rect.top / sb; i < (rect.top + rect.height) / sb; i++)
	{
		for (int j = rect.left / sb; j < (rect.left + rect.width) / sb; j++)
		{
			//std::cout << "i = " << i << " j = " << j << std::endl;
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
	std::cout << unit.getRect().top << std::endl;
	std::cout << unit.getRect().left << std::endl;
	return collised;
}
