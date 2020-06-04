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
	std::vector<Tile> TilesLine;
	Tile chunk;
	
	
	for (int i = 0; i < CharMap.size(); i++)
	{
		for (int j = 0; j < CharMap[i].size(); j++)
		{
			chunk.setTexture(*textures[CharMap[i][j]]);
			chunk.setScale(3.0f, 3.0f);
			chunk.setPosition(float(j * 60), float(i * 60));
			if (CharMap[i][j] == 'b')
				chunk.IsWall = true;
			else
				chunk.IsWall = false;
			TilesLine.push_back(chunk);
		}
		Location.push_back(TilesLine);
		TilesLine.clear();
	}
}

