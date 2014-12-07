#pragma once

#include "Pad.h"
#include "Ball.h"

class PongModel {
	public:
		PongModel();

	private:
		Pad left;
		Pad right;
		Ball ball;
};

