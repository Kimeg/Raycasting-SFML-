#include <SFML/Graphics.hpp>
#include "source.h"

Source::Source(int nRay, float x, float y, float radius, sf::Color color) 
{
	m_nRay = nRay;
	m_x = x;
	m_y = y;
	m_radius = radius;
	m_color = color;

	std::vector<sf::Color> colors{
		sf::Color(100,100,100),
	};

	for (int i = 0; i < m_nRay; i++) {
		float angle = i*360.f/(float)m_nRay;

		rays.push_back(Ray(m_x, m_y, angle, colors[rand() % colors.size()]));
	}
}

void Source::printCoords()
{
	std::cout << "source : (" << m_x << "," << m_y << ")" << std::endl;
}

void Source::Update(sf::Vector2i mousePos) 
{
	m_x = mousePos.x;
	m_y = mousePos.y;

	for (int i = 0; i < m_nRay; i++) {
		rays[i].Update(m_x, m_y);
	}
}

Source::~Source() {}