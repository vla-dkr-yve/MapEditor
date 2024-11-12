#pragma once
#include <SFML/Graphics.hpp>

#include "SaveLoadGUI.h"
#include "Map.h"
class Save
{
	std::string name = "Save";

	SaveLoadGUI saveBtn;

	int total;
public:
	Save();
	void Initialize();
	void Saving(const Map& map);
	void Update(sf::Vector2f mousePosition, const Map& map);
	void Draw(sf::RenderWindow& window);
};