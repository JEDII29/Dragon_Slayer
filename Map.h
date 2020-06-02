#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
class Map
{
public:
	std::vector<std::vector<sf::Sprite>> SpritesMap;
	std::vector<std::vector<char>> CharMap;

	Map(std::string location, std::map<char, sf::Texture*> textures);
	void LoadMap(std::string location);
	void CreateMap(std::map<char, sf::Texture*> textures);

};

