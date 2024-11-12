#pragma once
#include <SFML/Graphics.hpp>
#include "Gui.h"
#include "MouseTile.h"
#include "Map.h"
class Grid
{
	std::string name = "Grid";
	const sf::Vector2f m_cellSize = sf::Vector2f(16, 16);
	const int lineThickness = 1;
	sf::Vector2f m_totalCells;
	sf::Vector2f m_totalLines;
	sf::RectangleShape* vLine;
	sf::RectangleShape* hLine;
	sf::Vector2f m_scale;
	sf::Vector2f m_offset;
	float m_horizontalLineLenght;
	float m_vercticalLineLenght;
	int m_thickness;
public:
	Gui gui;
	Map map;
public:
	Grid(const sf::Vector2f& scale, const sf::Vector2f& totalCells, const sf::Vector2f& distance);
	void Initialize();
	void Load();
	void Update(const sf::Vector2f& mousePosition, MouseTile mouseTile, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	inline const sf::Vector2f& GetOffset() const { return m_offset; }
	inline const sf::Vector2f& GetSize() const { return m_totalCells; }
	inline const sf::Vector2f& GetScale() const { return m_scale; }
	inline const sf::Vector2f& GetCellSize() const { return m_cellSize; }
};