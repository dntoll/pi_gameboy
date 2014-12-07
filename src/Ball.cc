#include "Ball.h"


Ball::Ball() {
	x = 0.5f;
	y = 0.5f;
	dx = 1;
	dy = 1;
}

void Ball::update(float dt) {
	x += dx * dt;
	y += dy * dt;
}

float Ball::getX() const {
	return x;
}

float Ball::getY() const {
	return y;
}