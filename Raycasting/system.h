#ifndef SYSTEM_H
#define SYSTEM_H

#include "source.h"
#include "wall.h"

#include <iostream>
#include <vector>

class System 
{
public:
	int m_nRay, m_nWall, m_width, m_height;
	Source m_source;
	std::vector<Wall> m_walls;

	struct POI {
		float x, y;
	};

	System(int nRay, int nWall, int width, int height);
	~System();

	void printCoords();
	void Render();
	float calcDistance(float x1, float y1, float x2, float y2);

	POI getIntersectionPoint(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4);
};

#endif
