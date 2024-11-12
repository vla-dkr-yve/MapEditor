#pragma once
#include <SFML/Graphics.hpp>
class SaveLoadGUI
{
private:
	sf::Vector2f m_position;
	sf::Font font;
	sf::Text text;

	std::string m_name;
	const int m_width = 300;
	const int m_height = 100;
	const int outLineThickness = 1;
public:
	sf::RectangleShape btn;
public:
	SaveLoadGUI(std::string name, sf::Vector2f position = sf::Vector2f(0, 0));
	void Initialize();
	void btnHover();
	void Update(const sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};