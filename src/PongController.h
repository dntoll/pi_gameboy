#pragma once

#include "PongModel.h"
#include "PongView.h"

class PongController {
	public:
		PongController(PongModel &m, PongView &v, JoyStick &j);

		void update(float dt);
	private:
		PongModel &model;
		PongView &view;
		JoyStick &joyStick;
};

