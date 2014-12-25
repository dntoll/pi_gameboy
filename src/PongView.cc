#include "PongView.h"
#include <iostream>


using namespace std;

PongView::PongView(const PongModel &m, ili9341 &lcd) : model(m), screen(lcd) {
	ovx = 0;
	ovy = 0;

	screen.clearScreen();
}

void PongView::draw() {
	//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved
	//cout << "frame draw" << endl;

	/*bool foundNewValues = false;
	int fx = stick.getX();
	int fy = stick.getY();*/

	const Ball &b = model.getBall();
	//old ball
	screen.fillBox(ovx, ovy, 10, 10, 0, 0, 0);

	int vx = map(b.getX() * 1024, 0, 1024, 300, 10);
	int vy = map(b.getY() * 1024, 0, 1024, 220, 10);
	screen.fillBox(0, 0, 320, 10, 255, 255, 255);
	screen.fillBox(0, 230, 320, 10, 255, 255, 255);
	screen.fillBox(0, 0, 10, 240, 255, 255, 255);
	screen.fillBox(310, 0, 10, 240, 255, 255, 255);

	//Ball
	screen.fillBox(vx, vy, 10, 10, 255, 255, 0);
	ovx = vx;
	ovy = vy;
	//cout << "screen flush" << endl;
	screen.flush();
	//cout << "screen flushed" << endl;
}

int PongView::map(int v, int fromMin, int fromMax, int toMin, int toMax) {
	float fromRange = fromMax-fromMin;
	float fromAt = (v-fromMin)/fromRange;
	float toRange = toMax-toMin;
	
	return toMin + (fromAt * toRange);
}
