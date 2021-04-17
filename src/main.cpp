#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include <windows.h>

int main()
{
	FreeConsole();
	Game * game = nullptr;
	while (true)
	{
		game = new Game;
		game->start();
		delete game;
	}
	
}

/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>
#include <string>

int ground = 650;
const int W = 73, H = 18, sb = 20;
sf::String map[] =
{
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                   BBBB     BBBBBBBBBBBBBBBBBBBB      B",
	"B                                  BBBBB                               B",
	"BBBB                              BBBBBB                               B",
	"B                                BBBBBBB                               B",
	"B                               BBBBBBBB                               B",
	"B                              BBBBBBBBB                               B",
	"B                             BBBBBBBBBB                               B",
	"B                                                                      B",
	"B                                                                      B",
	"B                                                                      B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


using namespace sf;


float ofsetX = 0, ofsetY = 0;


class PLAYER
{
public:
	float dx, dy;
	FloatRect rect;
	bool exist;
	bool onGround;
	Sprite sprite;
	float currnetFrame;
	int bonus;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(0, 0, 15, 21);
		rect.left = 100;
		rect.top = 100;
		exist = true;
		dx = dy = 0.1;
		currnetFrame = 0;
		bonus = 1;
	}


	void update(float time)
	{
		rect.left += dx * time * bonus;
		if (exist)
			collision(0);

		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		//std::cout << dy;

		if (exist)
			collision(1);

		currnetFrame += 0.003 * time;

		if (currnetFrame > 2) currnetFrame = 0;

		if (dx < 0) sprite.setTextureRect(IntRect(19 + (16 * int(currnetFrame)), 0, 15, 21));
		if (dx == 0) sprite.setTextureRect(IntRect(19 + 15, 0, -15, 21));
		if (dx > 0) sprite.setTextureRect(IntRect(19 + (16 * int(currnetFrame)) + 15, 0, -15, 21));
		if (dy < 0 && onGround == false) sprite.setTextureRect(IntRect(67, 0, 16, 21));
		if (dy < 0 && onGround == false && Keyboard::isKeyPressed(Keyboard::Right)) sprite.setTextureRect(IntRect(67 + 16, 0, -16, 21));

		sprite.setPosition(rect.left - ofsetX, rect.top - ofsetY);

		dx = 0;
		//std::cout << rect.left << "=" << rect.top << std::endl;
	}


	void collision(bool dir)
	{
		for (int i = rect.top / sb; i < (rect.top + rect.height) / sb; i++)
			for (int j = rect.left / sb; j < (rect.left + rect.width) / sb; j++)
			{
				if (map[i][j] == 'B')
				{
					if (dx > 0 && dir == 0) { rect.left = j * sb - rect.width; }
					if (dx < 0 && dir == 0) { rect.left = j * sb + sb; }
					if (dy > 0 && dir == 1) { rect.top = i * sb - rect.height; dy = 0; onGround = true; }
					if (dy < 0 && dir == 1) { rect.top = i * sb + sb; dy = 0; }
				}
				if (map[i][j] == 'S')
				{
					map[i][j] = ' ';
					if (bonus < 2)
						bonus++;
				}
			}
	}

};

class ENEMY
{
public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;

	int width_text;
	bool onGround = false;
	bool exist;
	bool killed = false;
	float currnetFrame;

	ENEMY(Texture& image, int width_text)
	{
		this->width_text = width_text;
		sprite.setTexture(image);
		rect = FloatRect(0, 0, 21, 20);
		rect.left = 806;
		rect.top = 259;
		exist = true;
		dx = 0.05;
		dy = 0;
		currnetFrame = 0;
	}

	void update(float time)
	{
		if (exist)
		{
			rect.left += dx * time;

			if (!onGround) dy = dy + 0.0005 * time;
			rect.top += dy * time;

			if (collision(0) == 1 && !killed)
				dx *= -1;

			if (!killed)
				collision(1);

			currnetFrame += 0.003 * time;
			if (!killed)
			{
				if (currnetFrame > 3) currnetFrame = 0;
				if (dx < 0) sprite.setTextureRect(IntRect(0 + (width_text * int(currnetFrame)) + 21, 0, -21, 20));
				if (dx > 0) sprite.setTextureRect(IntRect(0 + (width_text * int(currnetFrame)), 0, 21, 20));
			}
			else if (rect.top > 480) exist = false;
		}
		sprite.setPosition(rect.left - ofsetX, rect.top - ofsetY);

	}

	bool collision(bool dir)
	{
		if (!killed)
			for (int i = rect.top / sb; i < (rect.top + rect.height) / sb; i++)
				for (int j = rect.left / sb; j < (rect.left + rect.width) / sb; j++)
				{
					if (map[i][j] == 'B')
					{

						if (dx > 0 ) { rect.left = j * sb - rect.width; return 1; }
						if (dx < 0 ) { rect.left = j * sb + sb; return 1; }
						if (dy > 0 ) { rect.top = i * sb - rect.height; dy = 0; onGround = true; }
						if (dy < 0 ) { rect.top = i * sb + sb; dy = 0; }
					}
				}
	}

	void kill()
	{
		sprite.setTextureRect(IntRect(67, 0, 20, 20));
		dy = -0.3;
		onGround = false;
		killed = true;
	}

};

void kill(PLAYER& pl, ENEMY& en)
{
	if (pl.rect.intersects(en.rect) && !en.killed)
	{
		if (en.exist && pl.exist)
		{
			if (pl.dy > 0.0007 && !pl.onGround)
			{
				en.kill();
				pl.dy -= 0.4;
				std::cout << "minus enemy";

			}
			else if (pl.onGround)
			{
				pl.dy -= 0.35;
				std::cout << "minus player";
				pl.exist = false;
			}
		}
	}
}

int main()
{

	RenderWindow window(VideoMode(640, 480), "TEST");

	Texture t, m, back, en, b;
	back.loadFromFile("res/backgrnd.png");
	t.loadFromFile("res/pl.png");
	m.loadFromFile("res/ground.png");
	en.loadFromFile("res/en1.png");
	b.loadFromFile("res/bonus.png");
	b.loadFromFile("res/bonus.png");

	Sprite Map, backgrnd, bonus;
	backgrnd.setTexture(back);
	Map.setTexture(m);
	bonus.setTexture(b);

	float currnetFrame = 0;

	PLAYER p(t);
	ENEMY e(en, 21);

	Clock clock;

	while (window.isOpen())
	{
		window.clear();
		window.draw(backgrnd);
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			p.dx = -0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			p.dx = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (p.onGround)
			{
				p.dy = -0.3;
				p.onGround = false;
			}
		}
		p.update(time);
		//e.update(time);
		kill(p, e);

		if (p.rect.top > 640 / 2) ofsetY = p.rect.top - 640 / 3;
		if (p.rect.left > 480 / 2) ofsetX = p.rect.left - 480 / 2;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == 'B') { Map.setPosition(sb * j - ofsetX, sb * i - ofsetY); window.draw(Map); }
				if (map[i][j] == 'S') { bonus.setPosition(sb * j - ofsetX, sb * i - ofsetY); window.draw(bonus); }
			}
		}
		if (e.exist)
			window.draw(e.sprite);
		std::cout << p.rect.top << std::endl;
		std:: cout << p.rect.left << std::endl;
		window.draw(p.sprite);
		window.display();
	}
}*/
