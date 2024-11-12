#pragma once
#include "SaveLoadGUI.h"
#include "Map.h"
#include "TileSheet.h"
class Load
{
	std::string name = "Load";
	SaveLoadGUI loadBtn;

public:
	Load();
	void Initialize();
	void Loading(Map& map, const TileSheet& tileSheet);
	void Update(sf::Vector2f mousePosition, Map& map, const TileSheet& tileSheet);
	void Draw(sf::RenderWindow& window);
};