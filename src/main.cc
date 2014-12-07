#include <iostream>
#include <stdlib.h>

#include "../../ili9341/src/ili9341.h"
#include <stdio.h>
#include "joystick.h"
#include "PongModel.h"
#include "PongView.h"
#include "PongController.h"

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

	PongModel pm;
	PongView pv(pm, lcd);
	PongController pc(pm, pv);

	lcd.setBrightness(255);
	lcd.clearScreen();

	

	lcd.fillBox(230, 310, 10, 10, rand()%255, rand()%255, rand()%255);
	int b = 0;
	
	do {
		pc.update();
		
	} while (stick.buttonDown() == false);

	lcd.clearScreen();
	
	
	
	return 0;
}
