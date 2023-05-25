#include <SFML/Graphics.hpp>
#include "system.h"

System::System(int nRay, int nWall, int width, int height) : m_source(180, 200.f, 200.f, 10.f, sf::Color::Green)
{
	m_nRay = nRay;
	m_nWall = nWall;
	m_width = width;
	m_height = height;
	
	std::vector<sf::Color> colors{
		sf::Color::Green,
		sf::Color::Red, 
		sf::Color::Yellow,
		sf::Color::Magenta,
	};

	m_walls.push_back(Wall(0, 0, 0, m_height, sf::Color::Black));
	m_walls.push_back(Wall(0, 0, m_width, 0, sf::Color::Black));
	m_walls.push_back(Wall(0, m_height, m_width, m_height, sf::Color::Black));
	m_walls.push_back(Wall(m_width, 0, m_width, m_height, sf::Color::Black));

	for (int i = 0; i < m_nWall; i++) {
		float x1 = rand() % m_width;
		float y1 = rand() % m_height;

		float x2 = rand() % m_width;
		float y2 = rand() % m_height;

		m_walls.push_back(Wall(x1, y1, x2, y2, colors[rand() % colors.size()]));
	}
}

void System::printCoords() 
{
	m_source.printCoords();

	for (int i = 0; i < m_walls.size(); i++) {
		m_walls[i].printCoords();
	}
}

System::POI System::getIntersectionPoint(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4)
{
	POI poi = { 0, 0 };

	float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	if (den == 0)
		return poi;

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
	float u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / den;

	if ((t > 0) && (t < 1) && (u > 0) && (u < 1)) {
		poi.x = x1 + t * (x2 - x1);
		poi.y = y1 + t * (y2 - y1);
	}

	//poi.x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / den;
	//poi.y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / den;
	return poi;
}

float System::calcDistance(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2.f) + pow(y1 - y2, 2.f));
}

void System::Render()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(m_width, m_height), "Ray Casting");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

		}

		std::vector<System::POI> pois;

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		m_source.Update(mousePos);

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		for (int i = 0; i < m_nRay; i++) {
			float min_dist = 9999.f;
			float x, y;

			float x1 = m_source.rays[i].m_x1;
			float x2 = m_source.rays[i].m_x2;
			float y1 = m_source.rays[i].m_y1;
			float y2 = m_source.rays[i].m_y2;

			for (int j = 0; j < m_walls.size(); j++) {
				float x3 = m_walls[j].m_x1;
				float x4 = m_walls[j].m_x2;
				float y3 = m_walls[j].m_y1;
				float y4 = m_walls[j].m_y2;

				System::POI	poi = getIntersectionPoint(x1, x2, x3, x4, y1, y2, y3, y4);

				if (!((poi.x == 0) && (poi.y == 0))) {
					float dist = calcDistance(m_source.m_x, m_source.m_y, poi.x, poi.y);

					if (dist < min_dist) {
						x = poi.x;
						y = poi.y;
						min_dist = dist;
					}
				}
			}

			pois.push_back(System::POI{ x, y });

			m_source.rays[i].line[1].position = sf::Vector2f(x, y);

			//line[1].position = sf::Vector2f(x, y);

			window.draw(m_source.rays[i].line);
		}

		/*for (int i = 0; i < m_nRay; i++) {
			window.draw(m_source.rays[i].line);
		}*/

		for (int i = 0; i < m_walls.size(); i++) {
			window.draw(m_walls[i].line);
		}

		for (int i = 0; i < pois.size(); i++) {
			System::POI poi = pois[i];

			sf::CircleShape circle;
			circle.setRadius(1);
			circle.setOutlineColor(sf::Color::Cyan);
			circle.setOutlineThickness(1);
			circle.setPosition(poi.x, poi.y);

			//window.draw(circle);
		}

		// end the current frame
		window.display();
	}
}

System::~System() {}

