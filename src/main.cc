#include <iostream>
#include <stdlib.h>

#include "../../ili9341/src/ili9341.h"
#include <stdio.h>
#include "joystick.h"
#include "pong.h"

using namespace std;

int map(int v, int fromMin, int fromMax, int toMin, int toMax) {
	float fromRange = fromMax-fromMin;
	float fromAt = (v-fromMin)/fromRange;
	float toRange = toMax-toMin;
	
	return toMin + (fromAt * toRange);
}

int main()
{
	JoyStick stick;
	
	ili9341 lcd;

	PongController pc;

	lcd.setBrightness(255);
	lcd.clearScreen();

	

	lcd.fillBox(230, 310, 10, 10, rand()%255, rand()%255, rand()%255);
	int b = 0;
	
	do {
		//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved
		bool foundNewValues = false;
		int fx = stick.getX();
		int fy = stick.getY();

		int vx = map(fx, 0, 1024, 230, 10);
		int vy = map(fy, 0, 1024, 310, 10);
		//lcd.clearScreen();
		lcd.fillBox(vx, vy, 1, 1, 255, 255, 0);
		
	} while (stick.buttonDown() == false);

	lcd.clearScreen();
	
	
	
	return 0;
}
