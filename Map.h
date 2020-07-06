#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
class Map
{
public:
	std::vector<std::vector<Tile>> Location;
	std::vector<std::vector<char>> CharMap;

	Map(std::string location, std::map<char, sf::Texture*> textures, std::vector<sf::Sprite*>& _grass);
	void LoadMap(std::string location);
	void CreateMap(std::map<char, sf::Texture*> textures, std::vector<sf::Sprite*>& _grass);

};

