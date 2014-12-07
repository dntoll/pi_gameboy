#pragma once

#include "Pad.h"
#include "Ball.h"

class PongModel {
	public:
		PongModel();


		const Ball& getBall() const;
	private:
		Pad left;
		Pad right;
		Ball ball;
};

