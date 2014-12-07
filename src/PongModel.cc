#include "PongModel.h"


PongModel::PongModel() {

}


void PongModel::update(float dt) {
	ball.update(dt);

	

}

const Ball& PongModel::getBall() const {
	return ball;
}