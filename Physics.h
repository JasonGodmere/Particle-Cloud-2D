#pragma once

#include "Clock.h"

class Physics : public Clock
{
public:
	virtual void Update() {  };
	double velocityX;
	double velocityY;
	double speedX;
	double speedY;
protected:
	double speed;
	float gravity = 0.01f;
	float forceX;
	float forceY;
	//double speedX;
	//double speedY;
	//double velocityX;
	//double velocityY;
	double accelerationX;
	double accelerationY;
};
