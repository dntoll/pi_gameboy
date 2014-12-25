#include "PongController.h"

PongController::PongController(PongModel &m, PongView &v, JoyStick &j) : model(m), view(v), joyStick(j) {
	
	
}


void PongController::update(float dt) {
	model.update(dt);

	view.draw();
}
