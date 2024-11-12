#include "Save.h"
#include "fstream"
Save::Save() :
	saveBtn(name)
{
	saveBtn.Initialize();
}
void Save::Saving(const Map& map)
{
	std::ofstream file;
	file.open("Assets/Maps/Grid.rmap", std::ofstream::out | std::ofstream::trunc);
	total = map.GetTotal();
	for (int i = 0; i < total; i++)
	{
		file << map.GetTileID(i) << ' ';
	}
	file.close();
}
void Save::Update(sf::Vector2f mousePosition, const Map& map)
{
	saveBtn.Update(mousePosition);
	if (saveBtn.btn.getGlobalBounds().contains(mousePosition))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			Saving(map);
		}
	}
}

void Save::Draw(sf::RenderWindow& window)
{
	saveBtn.Draw(window);
}