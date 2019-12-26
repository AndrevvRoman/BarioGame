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
	srand(time(NULL));
	std::ifstream in;
	std::string temp;
	uint16_t last = -1;
	uint16_t choosenPart = 3;
	size_t j = 0;
	map.resize(18);
	for (size_t i = 0; i < map.size(); i++)
	{
		map[i] += 'B';
	}
	const size_t N = 5;
	
	for (size_t i = 0; i < N; i++)
	{
		std::cout << "i = " << i << std::endl;
		j = 0;
		choosenPart = rand() % countOfParts;
		std::cout << "chosenPart = " << choosenPart << std::endl;
		while (choosenPart == last)
		{
			choosenPart = rand() % countOfParts;
			std::cout << "chosenPart = " << choosenPart << std::endl;
		}
		
		switch (choosenPart)
		{
		case 0:
		{
			
			in.open("res/part0.txt");
			while (std::getline(in, temp))
			{
				//map.resize(map.size() + 1);
				//std::cout << "temp = " << temp << std::endl;
				map[j] = map[j] + temp;
				j++;
				
			}
			in.close();
			break;
		}
		case 1:
		{
			in.open("res/part1.txt");
			
			while (std::getline(in, temp))
			{
				//map.resize(map.size() + 1);
				//std::cout << "temp = " << temp << std::endl;
				map[j] = map[j] + temp;
				j++;
			}
			in.close();
			break;
		}
		case 2:
		{
			in.open("res/part2.txt");
			while (std::getline(in,temp))
			{
				//map.resize(map.size() + 1);
				//std::cout << "temp = " << temp << std::endl;
				map[j] = map[j] + temp;
				j++;
			}
			in.close();
			break;
		}
		case 3:
		{

			in.open("res/part3.txt");
			while (std::getline(in, temp))
			{
				//map.resize(map.size() + 1);
				//std::cout << "temp = " << temp << std::endl;
				map[j] = map[j] + temp;
				j++;

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
			map[i] += 'B';
	}
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
}
