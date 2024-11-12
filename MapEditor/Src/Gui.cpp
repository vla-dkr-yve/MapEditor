#include "Gui.h"
#include <math.h>
Gui::Gui(sf::Vector2f size, sf::Vector2f position, std::string name) :
	m_size(size), m_position(position), m_name(name)
{
	isMoving = false;
	isDragging = false;
	btnHover = false;
	close = false;
}

void Gui::Initialize()
{
	m_guiForm.setSize(sf::Vector2f(m_size.x, m_size.y + m_titleBarHeight));
	m_guiForm.setPosition(m_position.x, m_position.y - m_titleBarHeight);
	m_guiForm.setOutlineThickness(m_outLineThickness);
	m_guiForm.setOutlineColor(sf::Color::White);
	m_guiForm.setFillColor(sf::Color::Black);

	m_titleBar.setSize(sf::Vector2f(m_size.x, m_titleBarHeight));
	m_titleBar.setPosition(m_position.x, m_position.y - m_titleBarHeight - m_outLineThickness - m_outLineThickness);
	m_titleBar.setOutlineThickness(m_outLineThickness);
	m_titleBar.setOutlineColor(sf::Color::White);
	m_titleBar.setFillColor(sf::Color::Black);

	m_font.loadFromFile("Assets/Fonts/Arial.TTF");
	m_text.setFont(m_font);
	m_text.setCharacterSize(30);
	m_text.setString(m_name);
	m_text.setPosition(m_titleBar.getPosition().x + 15, m_titleBar.getPosition().y);


	m_closeBtn.m_form = sf::RectangleShape(sf::Vector2f(m_titleBarHeight, m_titleBarHeight));
	m_closeBtn.m_form.setPosition(m_titleBar.getPosition().x + m_titleBar.getSize().x - m_titleBarHeight, m_titleBar.getPosition().y);
	m_closeBtn.m_form.setOutlineThickness(m_outLineThickness);
	m_closeBtn.m_form.setOutlineColor(sf::Color::White);
	m_closeBtn.m_form.setFillColor(sf::Color::Black);

	m_closeBtn.m_closeSignLines[0].setSize(sf::Vector2f(m_closeBtn.m_form.getSize().x - 4, 5.0));
	m_closeBtn.m_closeSignLines[0].setOrigin(sf::Vector2f(m_closeBtn.m_closeSignLines[0].getSize().x / 2, m_closeBtn.m_closeSignLines[0].getSize().y / 2));
	m_closeBtn.m_closeSignLines[0].setPosition(m_closeBtn.m_form.getPosition() + sf::Vector2f(m_closeBtn.m_form.getSize().x / 2, m_closeBtn.m_form.getSize().y / 2));
	m_closeBtn.m_closeSignLines[0].setRotation(45.0f);

	m_closeBtn.m_closeSignLines[1].setSize(sf::Vector2f(m_closeBtn.m_form.getSize().x - 4, 5.0));
	m_closeBtn.m_closeSignLines[1].setOrigin(sf::Vector2f(m_closeBtn.m_closeSignLines[1].getSize().x / 2, m_closeBtn.m_closeSignLines[1].getSize().y / 2));
	m_closeBtn.m_closeSignLines[1].setPosition(m_closeBtn.m_form.getPosition() + sf::Vector2f(m_closeBtn.m_form.getSize().x / 2, m_closeBtn.m_form.getSize().y / 2));
	m_closeBtn.m_closeSignLines[1].setRotation(135.0f);
}

void Gui::Update(const sf::Vector2f& mousePosition)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_titleBar.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
		isMoving = true;
		if (!isDragging)
		{
			direction = sf::Vector2f(mousePosition) - m_guiForm.getPosition();
			isDragging = true;
		}
		m_guiForm.setOutlineColor(sf::Color::Red);
		m_titleBar.setOutlineColor(sf::Color::Red);
		m_closeBtn.m_form.setOutlineColor(sf::Color::Red);

	}
	else {
		isMoving = false;
		isDragging = false;
		m_guiForm.setOutlineColor(sf::Color::White);
		m_titleBar.setOutlineColor(sf::Color::White);
		m_closeBtn.m_form.setOutlineColor(sf::Color::White);
	}
	if (isMoving)
	{
		int x = mousePosition.x - direction.x;
		int y = mousePosition.y - direction.y;
		m_position = sf::Vector2f(x, y);
		m_guiForm.setPosition(x, y);
		m_titleBar.setPosition(m_guiForm.getPosition().x, m_guiForm.getPosition().y - m_outLineThickness - m_outLineThickness);
		m_text.setPosition(m_titleBar.getPosition().x + 15, m_titleBar.getPosition().y);
		m_closeBtn.m_form.setPosition(m_titleBar.getPosition().x + m_titleBar.getSize().x - m_titleBarHeight, m_titleBar.getPosition().y);
		m_closeBtn.m_closeSignLines[0].setPosition(m_closeBtn.m_form.getPosition() + sf::Vector2f(m_closeBtn.m_form.getSize().x / 2, m_closeBtn.m_form.getSize().y / 2));
		m_closeBtn.m_closeSignLines[1].setPosition(m_closeBtn.m_form.getPosition() + sf::Vector2f(m_closeBtn.m_form.getSize().x / 2, m_closeBtn.m_form.getSize().y / 2));
	}
	if (m_closeBtn.m_form.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
		btnHover = true;
		if (btnHover)
		{
			m_closeBtn.m_form.setOutlineColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				close = true;
			}
		}
		else {
			m_closeBtn.m_form.setOutlineColor(sf::Color::White);
		}
	}

}

void Gui::Draw(sf::RenderWindow& window)
{
	if (!close)
	{
		window.draw(m_guiForm);
		window.draw(m_titleBar);
		window.draw(m_text);
		window.draw(m_closeBtn.m_form);
		window.draw(m_closeBtn.m_closeSignLines[0]);
		window.draw(m_closeBtn.m_closeSignLines[1]);
	}

}