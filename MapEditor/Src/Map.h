#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Tile.h"
#include "TileSheet.h"
class Map
{
private:
	sf::Sprite* m_mapSprites;

	bool* hasSprite;
	int* m_mapSpritesID;

	sf::Vector2f m_scale;

	int total;
public:
	Map(sf::Vector2f scale, sf::Vector2f totalCells);
	~Map();

	void Initialize();
	void Loading(const TileSheet& tileSheet);
	void Add(MouseTile mouseTile, const sf::Vector2f& gridSize, sf::Vector2f mousePosition, const sf::Vector2f& gridScale, const sf::Vector2f& gridOffset);
	void Move(sf::Vector2f offset, sf::Vector2f gridSize, sf::Vector2f gridTileSize, sf::Vector2f gridScale);
	void Remove(MouseTile mouseTile, const sf::Vector2f& gridSize, sf::Vector2f mousePosition, const sf::Vector2f& gridScale, const sf::Vector2f& gridOffset);
	void Update(MouseTile mouseTile, const sf::Vector2f& gridSize, const sf::Vector2f& gridScale, const sf::Vector2f& gridOffset, sf::Vector2f gridTileSize, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	inline void SetTileID(int i, int ID) { m_mapSpritesID[i] = ID; };
	const inline int GetTileID(int i)  const { return m_mapSpritesID[i]; };
	const inline int GetTotal()  const { return total; };
};