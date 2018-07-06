#pragma once

#include "Physics.h"
#include "Controls.h"

struct Particle : public Physics
{
	float pPosX;//previous
	float pPosY;//previous

	float legX;
	float legY;
	float posX;
	float posY;

	sf::RectangleShape rect;

	Particle();
	void Update(Clock *clock, Controls* controls, const int pI, const int pJ, const int size, std::vector<std::vector<Particle>>& otherP);
	void Draw(Clock *clock, Controls* controls, const int pI, const int pJ, const int size, std::vector<std::vector<Particle>>& otherP, sf::RenderWindow& window);

	void SetPosition(int x, int y) 
	{ 
		posX = x; 
		posY = y; 
		rect.setPosition(sf::Vector2f(posX, posY));
	};
protected:
	float mass;
	float hyp;
	
};