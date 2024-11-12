#include "SaveLoadGUI.h"
SaveLoadGUI::SaveLoadGUI(std::string name, sf::Vector2f position) :
	m_name(name)
{
	btn.setPosition(position);
	btn.setSize(sf::Vector2f(m_width, m_height));
	btn.setOutlineThickness(outLineThickness);
	btn.setFillColor(sf::Color::Black);
}

void SaveLoadGUI::Initialize()
{
	font.loadFromFile("Assets/Fonts/Arial.TTF");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString(m_name);
	text.setPosition(btn.getPosition() + sf::Vector2f((m_width / 2 - text.getCharacterSize() / 2) - 30, m_height / 2 - text.getCharacterSize() / 2));
}

void SaveLoadGUI::btnHover()
{
	btn.setOutlineColor(sf::Color::Red);
}

void SaveLoadGUI::Update(const sf::Vector2f& mousePosition)
{
	if (btn.getGlobalBounds().contains(mousePosition))
	{
		btnHover();
	}
	else {
		btn.setOutlineColor(sf::Color::White);
	}
}

void SaveLoadGUI::Draw(sf::RenderWindow& window)
{
	window.draw(btn);
	window.draw(text);
}