#pragma once

#include "Cloud.h"

struct Pixel
{
	char r, g, b, a;
};

class Screen// : protected Pixel
{
public:
	Screen(int x, int y);

	void Draw(Cloud *cloud, sf::RenderWindow& window);
protected:
	int width;
	int height;
	int sizeX;
	int sizeY;

	Pixel pixels[1080][1920];

	sf::RectangleShape pixel;
};