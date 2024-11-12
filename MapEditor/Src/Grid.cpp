#include "Grid.h"

Grid::Grid(const sf::Vector2f& scale, const sf::Vector2f& totalCells, const sf::Vector2f& distance) :
	m_scale(scale), m_totalCells(totalCells), m_offset(distance), gui(sf::Vector2f(m_totalCells.x* m_scale.x* m_cellSize.x,
		m_totalCells.y* m_scale.y* m_cellSize.y), m_offset + sf::Vector2f(2, 2), name), map(m_scale, m_totalCells)
{
	m_totalLines = m_totalCells + sf::Vector2f(1, 1);
}

void Grid::Initialize()
{
	m_vercticalLineLenght = m_totalCells.y * m_cellSize.y;
	m_horizontalLineLenght = m_totalCells.x * m_cellSize.x;

	vLine = new sf::RectangleShape[m_totalLines.x];
	for (int i = 0; i < m_totalLines.x; i++)
	{
		vLine[i].setSize(sf::Vector2f(lineThickness, m_vercticalLineLenght));
		vLine[i].setPosition(m_offset.x + i * m_scale.x * m_cellSize.x, m_offset.y);
		vLine[i].setScale(m_scale);
	}

	hLine = new sf::RectangleShape[m_totalLines.y];
	for (int i = 0; i < m_totalLines.y; i++)
	{
		hLine[i].setSize(sf::Vector2f(m_horizontalLineLenght, lineThickness));
		hLine[i].setPosition(m_offset.x + 2, m_offset.y + i * m_scale.y * m_cellSize.y);
		hLine[i].setScale(m_scale);
	}
	gui.Initialize();
	map.Initialize();
}

void Grid::Load()
{
}

void Grid::Update(const sf::Vector2f& mousePosition, MouseTile mouseTile, sf::RenderWindow& window)
{
	map.Update(mouseTile, m_totalCells, m_scale, m_offset, m_cellSize, window);
	gui.Update(mousePosition);
	if (gui.IsMoving())
	{
		vLine[0].setFillColor(sf::Color::Red);
		vLine[(int)m_totalLines.x - 1].setFillColor(sf::Color::Red);
		hLine[(int)m_totalLines.y - 1].setFillColor(sf::Color::Red);
		hLine[0].setFillColor(sf::Color::Red);
		m_offset = sf::Vector2f(gui.GetPosition().x - 2, gui.GetPosition().y + gui.GetTitleBarHeight() - 2);
		for (int i = 0; i < m_totalLines.x; i++)
		{
			vLine[i].setPosition(m_offset.x + i * m_scale.x * m_cellSize.x, m_offset.y);
		}
		for (int i = 0; i < m_totalLines.y; i++)
		{
			hLine[i].setPosition(m_offset.x + 2, m_offset.y + i * m_scale.y * m_cellSize.y);
		}
		map.Move(m_offset, m_totalCells, m_cellSize, m_scale);
	}
	else {
		vLine[0].setFillColor(sf::Color::White);
		hLine[0].setFillColor(sf::Color::White);
		vLine[(int)m_totalLines.x - 1].setFillColor(sf::Color::White);
		hLine[(int)m_totalLines.y - 1].setFillColor(sf::Color::White);
	}
}

void Grid::Draw(sf::RenderWindow& window)
{
	if (!gui.IsClosed())
	{
		gui.Draw(window);
		for (int i = 0; i < m_totalLines.y; i++)
		{
			window.draw(hLine[i]);
		}
		for (int i = 0; i < m_totalLines.x; i++)
		{
			window.draw(vLine[i]);
		}
		map.Draw(window);
	}
}