
#include "Cloud.h"

Cloud::Cloud(sf::RenderWindow& window)
{
	Particle particle;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			particlesI.push_back(particle);
			particlesI[j].SetPosition(i * 30 + 400, j * 30 + 200);
		}
		particles.push_back(particlesI);
	}

	/*for (int i = 0; i < window.getSize().y; i++)
	{
		for (int j = 0; j < window.getSize().x; j++)
		{
			densitiesI.push_back(0);
		}
		densities.push_back(densitiesI);
	}*/
}

void Cloud::Update(Clock *clock, sf::RenderWindow& window)
{
	
}

void Cloud::Draw(Clock* clock, Controls* controls, sf::RenderWindow& window)
{
	Cloud::Update(clock, window);

	if (controls->space)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size / 2; j++)
			{
				particles[i][j].Draw(clock, controls, i, j, size, particles, window);

				//if (particles[i].posX < window.getSize().x && particles[i].posY < window.getSize().y)
				//	densities[(int)particles[i].posY][(int)particles[i].posX] = 1;
			}
		}
	}
}