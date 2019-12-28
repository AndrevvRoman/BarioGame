#include "MapGenerator.h"
#include <fstream>
#include <iostream>
#include <ctime>

void MapGenerator::generate()
{
	for (size_t i = 0; i < map.size(); i++)
	{
		map[i].clear();
		map[i].resize(0);
	}
	map.clear();
	map.resize(0);
	std::ifstream in;
	std::string temp;
	uint16_t last = -1;
	uint16_t choosenPart = 3;
	size_t j = 0;

	const size_t N = 5;
	
	for (size_t i = 0; i < N; i++)
	{
		j = 0;
		choosenPart = rand() % countOfParts;
		while (choosenPart == last)
		{
			choosenPart = rand() % countOfParts;
		}
		
		switch (choosenPart)
		{
		case 0:
		{
			
			in.open("res/part0.txt");
			while (std::getline(in, temp))
			{
				mergePart(temp, j);
			}
			in.close();
			break;
		}
		case 1:
		{
			in.open("res/part1.txt");
			
			while (std::getline(in, temp))
			{
				mergePart(temp, j);
			}
			in.close();
			break;
		}
		case 2:
		{
			in.open("res/part2.txt");
			while (std::getline(in,temp))
			{
				mergePart(temp, j);
			}
			in.close();
			break;
		}
		case 3:
		{

			in.open("res/part3.txt");
			while (std::getline(in, temp))
			{
				mergePart(temp, j);
			}
			in.close();
			break;
		}
		}

		last = choosenPart;
		choosenPart = -1;
	}
	for (size_t i = 0; i < map.size(); i++)
	{
		map[i].insert(map[i].begin(), 'B');
		map[i] += 'B';
	}
	W = map[0].size();
	H = map.size();
}

void MapGenerator::mergePart(const std::string& temp, std::size_t & j)
{
	if (j >= map.size())
	{
		map.resize(j + 1);
	}
	map[j].append(temp);
	j++;
}
