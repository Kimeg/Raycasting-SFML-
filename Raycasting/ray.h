#ifndef RAY_H
#define RAY_H 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Ray 
{
public:
	const float PI = 3.1415926;
	const float RADIUS = 5000;

	float m_x1, m_y1, m_x2, m_y2, m_angle;
	sf::Color m_color;
	sf::VertexArray line;

	Ray(float x, float y, float angle, sf::Color color);
	~Ray();

	void printCoords();
	void Update(int x, int y);
};

#endif
