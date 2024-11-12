#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f m_scale;
	sf::Vector2f tileSize;
	sf::Vector2f m_offset;
	int m_currentTileID = 11;
	const sf::Vector2f m_MAXTileID = sf::Vector2f(24, 12);
public:
	MouseTile(const sf::Vector2f& offset, sf::Vector2f scale);

	bool IsOnTheGrid(sf::Vector2f mousePosition, const sf::Vector2f gridSize, const sf::Vector2f gridScale, const sf::Vector2f gridOffset);
	bool IsOnTheTileSheet(sf::Vector2f mousePosition, sf::Vector2f position, sf::Vector2f scale);
	void Initialize();
	void Load();
	void Update(sf::Vector2f mousePosition, const sf::Vector2f& gridSize, const sf::Vector2f& gridScale, const sf::Vector2f gridOffset,
		const sf::Vector2f& tileSheetPosition, const sf::Vector2f& tileSheetScale, bool GuiIsClosed, bool tileSheetGuiIsClosed,
		bool gridGuiIsMoving, bool tileSheetGuiIsMoving);

	void Draw(sf::RenderWindow& window);

	inline int GetCurrentTileID() { return m_currentTileID; }
	inline const sf::Sprite& GetSprite() const { return sprite; }
	inline const sf::Vector2f& GetPosition() const { return sprite.getPosition(); }
};