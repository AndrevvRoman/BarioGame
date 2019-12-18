#include "Sound.h"

void Sound::loadSound(const int pos, const std::string& path)
{
	if (pos >= buffer.size())
	{
		buffer.resize(pos + 1);
		buffer[pos].loadFromFile(path);
	}
	else
	{
		buffer[pos].loadFromFile(path);
	}
	
}

void Sound::playSound(const int pos)
{
	if (pos < buffer.size())
	{
		sound.setBuffer(buffer[pos]);
		sound.play();
	}
	else
	{
		throw std::exception();
	}
}
