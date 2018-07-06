#pragma once

#include "Define.h"
#include "Particle.h"
#include "Controls.h"

class Cloud : protected Particle
{
public:
	Cloud(sf::RenderWindow& window);
	void Update(Clock *clock, sf::RenderWindow& window);
	void Draw(Clock* clock, Controls* controls, sf::RenderWindow& window);

	std::vector<char> densitiesI;
	std::vector<std::vector<char>> densities;
protected:
	int size = 40; // square that because 2d vector

	std::vector<Particle> particlesI;
	std::vector<std::vector<Particle>> particles;
};