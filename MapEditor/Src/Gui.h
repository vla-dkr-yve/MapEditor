#pragma once
#include <SFML/Graphics.hpp>
#include "CloseBtn.h"
class Gui
{
	sf::Font m_font;
	sf::Text m_text;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	CloseBtn m_closeBtn;
	sf::RectangleShape m_titleBar;
	sf::RectangleShape m_guiForm;

	sf::Vector2f direction;
	sf::Vector2f m_secondPostion;
	bool isMoving;
	bool isDragging;
	bool btnHover;
	bool close;
	std::string m_name;
	const int m_titleBarHeight = 40;
	const int m_outLineThickness = 2;
public:
	Gui(sf::Vector2f size, sf::Vector2f position, std::string name);
	void Initialize();
	void Update(const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
	const inline bool IsClosed() { return close; }
	const inline bool IsMoving() { return isMoving; }
	const inline sf::Vector2f GetPosition() { return m_position; }
	const inline int GetTitleBarHeight() { return m_titleBarHeight; }
	const inline int GetOutlineThickness() { return m_outLineThickness; }
};
