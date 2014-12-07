#include "PongView.h"

PongView::PongView(const PongModel &m, ili9341 &lcd) : model(m), screen(lcd) {
	
}

void PongView::draw() {
	//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved
	/*bool foundNewValues = false;
	int fx = stick.getX();
	int fy = stick.getY();*/

	const Ball &b = model.getBall();
	/*int vx = map(, 0, 1024, 230, 10);
	int vy = map(fy, 0, 1024, 310, 10);
	//lcd.clearScreen();*/
	screen.fillBox(100, 100, 10, 10, 255, 255, 0);
}