#include <SFML/Graphics.hpp>
#include "ray.h"

Ray::Ray(float x, float y, float angle, sf::Color color) : line(sf::Lines, 2)
{
	m_angle = angle;
	m_color = color;

	Update(x, y);
}

void Ray::Update(int x, int y) 
{
	m_x1 = x;
	m_y1 = y;

	m_x2 = m_x1 + cos(m_angle * PI / 180.f) * RADIUS;
	m_y2 = m_y1 + sin(m_angle * PI / 180.f) * RADIUS;

	line[0].position = sf::Vector2f(m_x1, m_y1);
	line[1].position = sf::Vector2f(m_x2, m_y2);

	line[0].color = m_color;
	line[1].color = m_color;
}

Ray::~Ray() {}
