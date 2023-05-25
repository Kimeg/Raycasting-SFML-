#ifndef SOURCE_H
#define SOURCE_H

#include "ray.h"
#include <iostream>
#include <vector>

class Source 
{
public:
	int m_nRay;
	float m_x, m_y, m_radius;
	sf::Color m_color;
	std::vector<Ray> rays;

	Source(int nRay, float x, float y, float radius, sf::Color color);
	~Source();

	void printCoords();
	void Update(sf::Vector2i mousePos);
};

#endif
