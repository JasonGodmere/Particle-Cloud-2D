
#include "Screen.h"

Screen::Screen(int x, int y)
{
	width = x;
	height = y;

	pixel.setSize(sf::Vector2f(1,1));
}

void Screen::Draw(Cloud* cloud, sf::RenderWindow& window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (cloud->densities[i][j] > 0)
			{
				pixel.setFillColor(sf::Color::Blue);
				pixel.setPosition(j, i);
				window.draw(pixel);
			}
		}
	}
}