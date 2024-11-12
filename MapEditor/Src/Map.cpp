#include "Map.h"
Map::Map(sf::Vector2f scale, sf::Vector2f totalCells) :
	m_scale(scale)
{
	total = totalCells.y * totalCells.x;
	m_mapSprites = new sf::Sprite[total];
	hasSprite = new bool[total];
	m_mapSpritesID = new int[total];
	for (int i = 0; i < total; i++)
	{
		m_mapSpritesID[i] = -1;
	}
}
Map::~Map()
{
	delete[] m_mapSprites;
	delete[] hasSprite;
}
void Map::Initialize() {

}

void Map::Loading(const TileSheet& tileSheet)
{
	for (int i = 0; i < total; i++)
	{
		m_mapSprites[i] = tileSheet.GetSpriteByID(m_mapSpritesID[i]);
		m_mapSprites[i].setScale(m_scale);
		if (m_mapSpritesID[i] == -1) {
			hasSprite[i] = false;
		}
		else {
			hasSprite[i] = true;
		}
	}
}


void Map::Add(MouseTile mouseTile, const sf::Vector2f& gridSize, sf::Vector2f mousePosition, const sf::Vector2f& gridScale, const sf::Vector2f& gridOffset) {
	if (mouseTile.IsOnTheGrid(mousePosition, gridSize, gridScale, gridOffset)) {
		int x = (mouseTile.GetPosition().x - gridOffset.x) / (16 * m_scale.x);
		int y = (mouseTile.GetPosition().y - gridOffset.y) / (16 * m_scale.y);
		int i = x + y * gridSize.x;
		m_mapSprites[i] = mouseTile.GetSprite();
		m_mapSpritesID[i] = mouseTile.GetCurrentTileID();
		hasSprite[i] = true;
	}
}

void Map::Move(sf::Vector2f offset, sf::Vector2f gridSize, sf::Vector2f gridTileSize, sf::Vector2f gridScale)
{
	for (int y = 0; y < gridSize.y; y++)
	{
		for (int x = 0; x < gridSize.x; x++)
		{
			int i = x + y * gridSize.x;
			m_mapSprites[i].setPosition(sf::Vector2f(offset.x + x * gridTileSize.x * gridScale.x, offset.y + y * gridTileSize.y * gridScale.y));
		}
	}
}

void Map::Remove(MouseTile mouseTile, const sf::Vector2f& gridSize, sf::Vector2f mousePosition, const sf::Vector2f& gridScale, const sf::Vector2f& gridOffset)
{
	if (mouseTile.IsOnTheGrid(mousePosition, gridSize, gridScale, gridOffset)) {
		int x = (mouseTile.GetPosition().x - gridOffset.x) / (16 * gridScale.x);
		int y = (mouseTile.GetPosition().y - gridOffset.y) / (16 * gridScale.y);
		int i = x + y * gridSize.x;
		if (hasSprite[i]) {
			hasSprite[i] = false;
			m_mapSpritesID[i] = -1;
		}

	}
}

void Map::Update(MouseTile mouseTile, const sf::Vector2f& gridSize, const  sf::Vector2f& gridScale, const sf::Vector2f& gridOffset, sf::Vector2f gridTileSize, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		Add(mouseTile, gridSize, sf::Vector2f(sf::Mouse::getPosition(window)), gridScale, gridOffset);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		Remove(mouseTile, gridSize, sf::Vector2f(sf::Mouse::getPosition(window)), gridScale, gridOffset);
	}
	Move(gridOffset, gridSize, gridTileSize, gridScale);
}

void Map::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < total; i++)
	{
		if (hasSprite[i]) {
			window.draw(m_mapSprites[i]);
		}
	}
}