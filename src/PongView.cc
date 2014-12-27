#include "PongView.h"
#include <iostream>


using namespace std;

PongView::PongView(const PongModel &m, BackBuffer &lcd) : model(m), screen(lcd) {
	ovx = 0;
	ovy = 0;

	screen.clearScreen();
}

void PongView::draw() {
	//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved

	/*bool foundNewValues = false;
	int fx = stick.getX();
	int fy = stick.getY();*/

	const Ball &b = model.getBall();
	//old ball
	screen.fillBox(Rect(ovx-1, ovy-1, 12, 12), Color::BLACK);

	int vx = map(b.getX() * 1024, 0, 1024, 300, 10);
	int vy = map(b.getY() * 1024, 0, 1024, 220, 10);
	screen.fillBox(Rect(0, 0, 320, 10), Color(255, 0, 0));
	screen.fillBox(Rect(0, 230, 320, 10), Color(255, 0, 0));
	screen.fillBox(Rect(0, 0, 10, 240), 0, Color(255, 0));
	screen.fillBox(Rect(310, 0, 10, 240), Color(255, 0, 255));

	//Ball
	screen.fillBox(Rect(vx, vy, 10, 10), Color(255, 255, 0));
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
