#ifndef WALL_H
#define WALL_H 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Wall
{
public:
	float m_x1, m_y1, m_x2, m_y2;

	sf::Color m_color;
	sf::VertexArray line;

	Wall(float x1, float y1, float x2, float y2, sf::Color color);
	~Wall();

	void printCoords();
};

#endif
