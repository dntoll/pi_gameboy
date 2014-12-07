#include "PongController.h"

PongController::PongController(PongModel &m, PongView &v) : model(m), view(v) {
	
	
}


void PongController::update(float dt) {
	model.update(dt);

	view.draw();
}