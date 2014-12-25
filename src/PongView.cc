#include "PongView.h"





PongView::PongView(const PongModel &m, ili9341 &lcd) : model(m), screen(lcd) {
	
}

void PongView::draw() {
	//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved
	std::cout << "frame draw" << endl;
	screen.clearScreen();
	/*bool foundNewValues = false;
	int fx = stick.getX();
	int fy = stick.getY();*/

	const Ball &b = model.getBall();
	int vx = map(b.getX() * 1024, 0, 1024, 230, 10);
	int vy = map(b.getY() * 1024, 0, 1024, 310, 10);
	std::cout << "fill box" << endl;
	screen.fillBox(ovx, ovy, 10, 10, 0, 0, 0);
	screen.fillBox(vx, vy, 10, 10, 255, 255, 0);
	ovx = vx;
	ovy = vy;

	screen.flush();
}

int PongView::map(int v, int fromMin, int fromMax, int toMin, int toMax) {
	float fromRange = fromMax-fromMin;
	float fromAt = (v-fromMin)/fromRange;
	float toRange = toMax-toMin;
	
	return toMin + (fromAt * toRange);
}
