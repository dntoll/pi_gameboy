#pragma once

#include "Pad.h"
#include "Ball.h"

class PongModel {
	public:
		PongModel();

		void update(float dt);

		const Ball& getBall() const;
	private:
		Pad left;
		Pad right;
		Ball ball;
};

