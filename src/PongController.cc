#include "PongController.h"

PongController::PongController(PongModel &m, PongView &v) : model(m), view(v) {
	
	
}


void PongController::update() {

	
	view.draw();
}