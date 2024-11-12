#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Gui.h"
class TileSheet
{
private:
	const std::string name = "Tile sheet";

	sf::Sprite* m_tileSheetSprites;
	Tile* m_tiles;

	sf::Texture m_texture;
	sf::Vector2f m_scale;
	sf::Vector2f m_originalPosition;

	const int m_tileWidth = 16;
	const int m_tileHeight = 16;
	const int m_tileSheetWidth = 24;
	const int m_tileSheetHeight = 12;

public:
	Gui gui;
public:
	TileSheet(sf::Vector2f scale, sf::Vector2f originalPosition);
	~TileSheet();
	void Initialize();
	void Load();
	void Update(const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);

	inline const sf::Vector2f GetPosition() const { return m_originalPosition; }
	inline const sf::Vector2f GetScale() const { return m_scale; }
	inline const int GetTileSheetWidth() const { return m_tileSheetWidth; }
	inline const int GetTileSheetHeight() const { return m_tileSheetHeight; }
	inline const int GetTileSheetTileWidth() const { return m_tileWidth; }
	inline const int GetTileSheetTileHeight() const { return m_tileHeight; }
	const inline sf::Sprite GetSpriteByID(int ID) const { return m_tileSheetSprites[ID]; };
};