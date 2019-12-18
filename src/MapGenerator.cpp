#include "MapGenerator.h"
#include <fstream>
#include <iostream>

void MapGenerator::generate()
{
	std::ifstream in;
	std::string temp;
	uint16_t last = 0;
	uint16_t choosenPart = 0;
	map.resize(18);
	for (size_t i = 0; i < map.size(); i++)
	{
		map[i].resize(map[i].size() + 1);
		for (size_t j = map[i].size() - 1; j < map[i].size(); j++)
			map[i][j] = 'B';
	}
	const size_t N = 3;
	for (size_t i = 0; i < N; i++)
	{
		while (choosenPart == last)
		{
			choosenPart = rand() % countOfParts;
		}

		switch (choosenPart)
		{
		case 0:
		{
			
			in.open("res/part0.txt");
			size_t i = 0;
			while (in >> temp)
			{
				map.resize(map.size() + 1);
				std::cout << "temp = " << temp << std::endl;
				map[i] = map[i] + temp;
				i++;
			}
			break;
		}
		case 1:
		{
			in.open("res/part1.txt");
			size_t i = 0;
			while (in >> temp)
			{
				map.resize(map.size() + 1);
				std::cout << "temp = " << temp << std::endl;
				map[i] = map[i] + temp;
				i++;
			}
			break;
		}
		case 2:
		{
			in.open("res/part2.txt");
			size_t i = 0;
			while (std::getline(in,temp))
			{
				//map.resize(map.size() + 1);
				std::cout << "temp = " << temp << std::endl;
				map[i] = map[i] + temp;
				i++;
			}
			break;
		}
		default:
			break;
		}
	}
	for (size_t i = 0; i < map.size(); i++)
	{
		map[i].resize(map[i].size() + 1);
		for (size_t j = map[i].size() - 1; j < map[i].size(); j++)
			map[i][j] = 'B';
	}
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
}
