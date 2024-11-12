#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "TileSheet.h"
#include "Gui.h"
#include "Save.h"
#include "Load.h"


int main() {
	//------------Initializing------------

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Map Editor");
	//window.setFramerateLimit(500);
	//------------Initializing------------
	Grid grid(sf::Vector2f(4, 4), sf::Vector2f(10, 5), sf::Vector2f(100, 300));
	MouseTile mouseTile(grid.GetOffset(), grid.GetScale());
	TileSheet tileSheet(sf::Vector2f(2, 2), sf::Vector2f(900 + 100, 300));
	Save saveBtn;
	Load loadBtn;

	grid.Initialize();
	mouseTile.Initialize();
	tileSheet.Initialize();
	//------------Load------------

	sf::Clock clock;
	tileSheet.Load();

	//------------Load------------

	while (window.isOpen()) {
		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();

		//------------Update------------
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		saveBtn.Update(sf::Vector2f(sf::Mouse::getPosition(window)), grid.map);
		loadBtn.Update(sf::Vector2f(sf::Mouse::getPosition(window)), grid.map, tileSheet);
		mouseTile.Update(sf::Vector2f(sf::Mouse::getPosition(window)), grid.GetSize(), grid.GetScale(), grid.GetOffset(),
			tileSheet.GetPosition(), tileSheet.GetScale(), grid.gui.IsClosed(), tileSheet.gui.IsClosed(), grid.gui.IsMoving(), tileSheet.gui.IsMoving());
		if (!grid.gui.IsMoving() && !tileSheet.gui.IsMoving())
		{
			grid.map.Update(mouseTile, grid.GetSize(), grid.GetScale(), grid.GetOffset(), grid.GetCellSize(), window);
		}
		if (!grid.gui.IsMoving())
		{
			tileSheet.Update(sf::Vector2f(sf::Mouse::getPosition(window)));
		}
		if (!tileSheet.gui.IsMoving())
		{
			grid.Update(sf::Vector2f(sf::Mouse::getPosition(window)), mouseTile, window);
		}
		//------------Update------------

		//------------Draw--------------
		window.clear(sf::Color::Black);
		tileSheet.Draw(window);
		grid.Draw(window);
		mouseTile.Draw(window);
		saveBtn.Draw(window);
		loadBtn.Draw(window);
		window.display();

		//------------Draw--------------
	}

	return 0;
}