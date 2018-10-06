
#include "Particle.h"

Particle::Particle()
{
	mass = 10;
	speedX = 0;
	speedY = 0;
	velocityX = 0;
	velocityY = 0;
	accelerationX = 0;
	accelerationY = 0;

	rect.setFillColor(sf::Color(255, 255, 255, 50));
	rect.setSize(sf::Vector2f(5,5));
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
}

void Particle::Update(Clock *clock, Controls* controls, const int pI, const int pJ, const int size, std::vector<std::vector<Particle>>& otherP)
{
	time = clock->time;

	accelerationX = 0;
	accelerationY = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			legX = otherP[i][j].pPosX - pPosX;
			legY = otherP[i][j].pPosY - pPosY;
			hyp = std::abs(sqrt(pow(legX, 2) + pow(legY, 2)));

			if (hyp > otherP[i][j].rect.getSize().x / 2 && hyp != 0)
			{
				if (pI != i && pJ != j)//x acceleration
				{
					forceX = gravity * otherP[i][j].mass * mass * (legX / hyp);

					accelerationX += (forceX / mass);

					//accelerationY += gravity * otherP[i].mass * mass; // pow(legY, 2);
					//accelerationX = 100;
				}

				if (pI != i && pJ != j)//y acceleration
				{
					forceY = gravity * otherP[i][j].mass * mass * (legY / hyp);

					accelerationY += (forceY / mass);
				}
			}
		}
	}

	//for mouse interaction
	/*legX = controls->mousePosX - posX;
	legY = controls->mousePosY - posY;
	hyp = std::abs(sqrt(pow(legX, 2) + pow(legY, 2)));

	if (hyp > 5)
	{
		if (legX != 0)//x acceleration
		{
			//accelerationX += gravity * 20000 * mass / hyp * (legX / hyp);

			//accelerationY += gravity * otherP[i].mass * mass; // pow(legY, 2);
			//accelerationX = 100;
		}

		if (legY != 0)//y acceleration
		{
			//accelerationY += gravity * 20000 * mass / hyp * (legY / hyp);
		}
	}*/
	//mouse interaction

	accelerationX = accelerationX * time;
	accelerationY = accelerationY * time;

	speedX += accelerationX;
	speedY += accelerationY;

	//speedX = speedX * .9999f;
	//speedY = speedY * .9999f;

	velocityX = speedX * time;
	velocityY = speedY * time;

	posX += velocityX;
	posY += velocityY;

	rect.setPosition(posX, posY);

	pPosX = posX;
	pPosY = posY;
}

void Particle::Draw(Clock* clock, Controls* controls, const int pI, const int pJ, const int size, std::vector<std::vector<Particle>>& otherP, sf::RenderWindow& window)
{
	Particle::Update(clock, controls, pI, pJ, size, otherP);

	window.draw(rect);
}