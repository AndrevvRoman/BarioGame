#pragma once
#include <SFML/Audio.hpp>
#include <vector>
class Sound
{
public:
	enum
	{
		jump = 0,
		hit = 1,
		damage = 2,
	};
	std::vector<sf::SoundBuffer> buffer;
	sf::Sound sound;
	void loadSound(const int pos,const std::string & path);
	void playSound(const int pos);
};

