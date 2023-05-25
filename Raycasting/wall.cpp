#include <SFML/Graphics.hpp>
#include "wall.h"

Wall::Wall(float x1, float y1, float x2, float y2, sf::Color color) : line(sf::Lines, 2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;

	m_color = color;

	line[0].position = sf::Vector2f(m_x1, m_y1);
	line[1].position = sf::Vector2f(m_x2, m_y2);
	line[0].color = m_color;
	line[1].color = m_color;
}

void Wall::printCoords() 
{
	std::cout << "Wall : (" << m_x1 << "," << m_y1 << "," << m_x2 << "," << m_y2 << ")" << std::endl;
}

Wall::~Wall() {}
