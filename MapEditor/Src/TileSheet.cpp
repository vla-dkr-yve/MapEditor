#include "TileSheet.h"

TileSheet::TileSheet(sf::Vector2f scale, sf::Vector2f originalPosition) :
	m_scale(scale), m_originalPosition(originalPosition), gui(sf::Vector2f(m_tileWidth* m_scale.x* m_tileSheetWidth, m_tileHeight* m_scale.y* m_tileSheetHeight),
		sf::Vector2f(m_originalPosition.x, m_originalPosition.y), name)
{
}

TileSheet::~TileSheet()
{
	delete[] m_tiles;
	delete[] m_tileSheetSprites;
}

void TileSheet::Initialize()
{
	gui.Initialize();
}

void TileSheet::Load()
{
	m_tileSheetSprites = new sf::Sprite[m_tileSheetHeight * m_tileSheetWidth];
	m_texture.loadFromFile("Assets/World/Prison/Dungeon_tileset.png");
	m_tiles = new Tile[m_tileSheetHeight * m_tileSheetWidth];
	for (int y = 0; y < m_tileSheetHeight; y++) {
		for (int x = 0; x < m_tileSheetWidth; x++) {
			int i = x + y * m_tileSheetWidth;
			m_tiles[i].id = i;
			m_tiles[i].TextureRect = sf::Vector2i(m_tileWidth * x, m_tileHeight * y);
		}
	}
	for (int y = 0; y < m_tileSheetHeight; y++) {
		for (int x = 0; x < m_tileSheetWidth; x++) {
			int i = x + y * m_tileSheetWidth;
			m_tileSheetSprites[i].setTexture(m_texture);
			m_tileSheetSprites[i].setTextureRect(sf::IntRect(m_tiles[i].TextureRect, sf::Vector2i(16, 16)));
			m_tileSheetSprites[i].setScale(m_scale);
			m_tileSheetSprites[i].setPosition(m_originalPosition.x + x * m_tileWidth * m_scale.x, m_originalPosition.y + y * m_tileHeight * m_scale.y);
		}
	}
}

void TileSheet::Update(const sf::Vector2f& mousePosition)
{
	gui.Update(mousePosition);
	if (gui.IsMoving())
	{
		m_originalPosition = sf::Vector2f(gui.GetPosition().x, gui.GetPosition().y + gui.GetTitleBarHeight());
		for (int y = 0; y < m_tileSheetHeight; y++) {
			for (int x = 0; x < m_tileSheetWidth; x++) {
				int i = x + y * m_tileSheetWidth;
				m_tileSheetSprites[i].setPosition(m_originalPosition.x + x * m_tileWidth * m_scale.x,
					m_originalPosition.y + y * m_tileHeight * m_scale.y);
			}
		}
	}
}

void TileSheet::Draw(sf::RenderWindow& window)
{
	if (!gui.IsClosed())
	{
		gui.Draw(window);
		for (int i = 0; i < m_tileSheetHeight * m_tileSheetWidth; i++)
		{
			window.draw(m_tileSheetSprites[i]);
		}
	}
}