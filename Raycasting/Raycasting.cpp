#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "system.h"

using namespace std;

int main()
{
	srand(time(0));

	int nWall = 20;
	int nRay = 180;
	int width = 400;
	int height = 300;

	System system(nRay, nWall, width, height);
	system.printCoords();
	system.Render();

    return 0;
}

