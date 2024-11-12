#include "MouseTile.h"
#include <iostream>
MouseTile::MouseTile(const sf::Vector2f& offset, sf::Vector2f scale) :
	m_scale(scale), tileSize(16, 16), m_offset(offset)
{
}

bool MouseTile::IsOnTheGrid(sf::Vector2f mousePosition, const sf::Vector2f gridSize, const sf::Vector2f gridScale, const sf::Vector2f gridOffset)
{
	if (mousePosition.x > gridOffset.x && mousePosition.x < gridSize.x * tileSize.x * gridScale.x + gridOffset.x &&
		mousePosition.y > gridOffset.y && mousePosition.y < gridSize.y * tileSize.y * gridScale.y + gridOffset.y) {
		return true;
	}
	return false;
}

bool MouseTile::IsOnTheTileSheet(sf::Vector2f mousePosition, sf::Vector2f position, sf::Vector2f scale)
{
	if (mousePosition.x > position.x && mousePosition.x < position.x * tileSize.x * scale.x &&
		mousePosition.y > position.y && mousePosition.y < position.y * tileSize.y * scale.y) {
		return true;
	}
	return false;
}

void MouseTile::Initialize()
{
	texture.loadFromFile("Assets/World/Prison/Dungeon_tileset.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(tileSize.x * m_currentTileID, 0 * tileSize.y, tileSize.x, tileSize.y));
	sprite.setScale(m_scale);
	sprite.setPosition(m_offset);
}

void MouseTile::Load()
{
}

void MouseTile::Update(sf::Vector2f mousePosition, const sf::Vector2f& gridSize, const sf::Vector2f& gridScale, const sf::Vector2f gridOffset,
	const sf::Vector2f& tileSheetPosition, const sf::Vector2f& tileSheetScale, bool gridGuiIsClosed, bool tileSheetGuiIsClosed,
	bool gridGuiIsMoving, bool tileSheetGuiIsMoving)
{
	//Teking texture form the tilesheet when LMB is clicked 
	if (IsOnTheTileSheet(mousePosition, tileSheetPosition, tileSheetScale) && !tileSheetGuiIsClosed && !gridGuiIsMoving && !tileSheetGuiIsMoving) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			int intX = (mousePosition.x - tileSheetPosition.x) / (tileSize.x * tileSheetScale.x);
			int intY = (mousePosition.y - tileSheetPosition.y) / (tileSize.y * tileSheetScale.y);
			if (intX < 24 && intY < 12)
			{
				m_currentTileID = intX + intY * m_MAXTileID.x;
				sprite.setTextureRect(sf::IntRect(tileSize.x * intX, intY * tileSize.y, tileSize.x, tileSize.y));
			}
		}
	}
	//Placing it on the grid(not adding, just placing)
	if (IsOnTheGrid(mousePosition, gridSize, gridScale, gridOffset) && !gridGuiIsClosed) {
		int intX = (mousePosition.x - gridOffset.x) / (tileSize.x * gridScale.x);
		int x = intX * tileSize.x * gridScale.x + gridOffset.x;

		int intY = (mousePosition.y - gridOffset.y) / (tileSize.y * gridScale.y);
		int y = intY * tileSize.y * gridScale.y + gridOffset.y;
		sprite.setPosition(x, y);
	}
	//Placing it out of the grid(not adding, just placing)
	else {
		sprite.setPosition(mousePosition.x - (tileSize.x * m_scale.x) / 2, mousePosition.y - (tileSize.y * m_scale.y) / 2);
	}
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}