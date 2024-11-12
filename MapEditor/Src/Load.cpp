#include "Load.h"
#include "fstream"
Load::Load() :
	loadBtn(name, sf::Vector2f(302, 0))
{
	loadBtn.Initialize();
}
void Load::Loading(Map& map, const TileSheet& tileSheet)
{
	std::string line;
	std::ifstream file;
	file.open("Assets/Maps/Grid.rmap");
	int total = map.GetTotal();
	int offset = 0;
	std::getline(file, line);
	for (int i = 0; i < total; i++)
	{
		int count = line.find(" ", offset);
		std::string mapVal = line.substr(offset, count - offset);
		map.SetTileID(i, std::stoi(mapVal));
		offset = count + 1;
	}
	file.close();
	map.Loading(tileSheet);
}
void Load::Update(sf::Vector2f mousePosition, Map& map, const TileSheet& tileSheet)
{
	loadBtn.Update(mousePosition);
	if (loadBtn.btn.getGlobalBounds().contains(mousePosition))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			Loading(map, tileSheet);
		}
	}
}

void Load::Draw(sf::RenderWindow& window)
{
	loadBtn.Draw(window);
}