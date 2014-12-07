#include "Ball.h"


Ball::Ball() {
	x = 0.5f;
	y = 0.5f;
	dx = 1;
	dy = 2;
}

void Ball::update(float dt) {
	x += dx * dt;
	y += dy * dt;

	//roof 
	if (y > 1.0f) {
		y = 1.0f;
		dy = -dy;
	}
	//floor
	if (y < 0.0f) {
		y = 0.0f;
		dy = -dy;
	}

	//roof 
	if (x > 1.0f) {
		x = 1.0f;
		dx = -dx;
	}
	//floor
	if (x < 0.0f) {
		x = 0.0f;
		dx = -dx;
	}
}

float Ball::getX() const {
	return x;
}

float Ball::getY() const {
	return y;
}