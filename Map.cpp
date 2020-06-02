#include "Map.h"

Map::Map(std::string location, std::map<char, sf::Texture*> textures)
{
	LoadMap(location);
	CreateMap(textures);
}

void Map::LoadMap(std::string location)
{
	std::ifstream file(location);
	std::string charLine;
	std::vector<char> mapLine;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, charLine);
			for (int i = 0; i < charLine.length(); i++)
			{
				mapLine.push_back(charLine[i]);
			}
			CharMap.push_back(mapLine);
			mapLine.clear();
			charLine.clear();
		}
	}
}


void Map::CreateMap(std::map<char, sf::Texture*> textures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;
	
	
	for (int i = 0; i < CharMap.size(); i++)
	{
		for (int j = 0; j < CharMap[i].size(); j++)
		{
			chunk.setTexture(*textures[CharMap[i][j]]);
			chunk.setScale(3.0f, 3.0f);
			chunk.setPosition(float(j * 60), float(i * 60));
			spritesLine.push_back(chunk);
		}
		SpritesMap.push_back(spritesLine);
		spritesLine.clear();
	}
}

//for (auto& [name, texture] : map_textures) {
//	sf::Sprite* s = new sf::Sprite;
//	if (name == "asky") {
//		s->setTexture(*texture);
//		s->setScale(2.0f, 2.0f);
//		s->setTextureRect(sf::IntRect(0, 0, 800, 600));
//		this->sprites.emplace_back(s);
//	}
//	if (name == "clouds") {
//		s->setTexture(*texture);
//		s->setScale(1.0f, 1.0f);
//		s->setTextureRect(sf::IntRect(0, 0, 800, 300));
//		s->setPosition(0.0f, 200.0f);
//		this->sprites.emplace_back(s);
//	}