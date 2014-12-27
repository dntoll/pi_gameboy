#include <iostream>
#include <stdlib.h>

#include "../../ili9341/src/BackBuffer.h"
#include "../../ili9341/src/ili9341.h"

#include <stdio.h>
#include "joystick.h"
#include "PongModel.h"
#include "PongView.h"
#include "PongController.h"
#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <math.h>
#include <time.h>

using namespace std;


long            last_ms; // Milliseconds
time_t          last_s;  // Seconds

float getCurrentTimeElapsed()
{
    long            ms; // Milliseconds
    time_t          s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds

    time_t es = s-last_s;
    long ems = ms-last_ms;

    last_ms = ms;
    last_s = s;

    return (float)es + (float)ems/1000.0f;

}


int main()
{
	JoyStick stick;
	
	ili9341 lcd;
	BackBuffer bb(lcd)

	PongModel pm;
	PongView pv(pm, bb);
	PongController pc(pm, pv, stick);
	cout << "startup" << endl;

	lcd.setBrightness(255);
	bb.clearScreen();

	getCurrentTimeElapsed(); //to remove the false values

	do {
		//cout << "frame start" << endl;
		float dt = getCurrentTimeElapsed();

		//cout << "controller update" << endl;
		pc.update(dt);
		cout << 1.0f/dt << endl;
		
	} while (stick.buttonDown() == false);

	bb.clearScreen();
	
	
	
	return 0;
}
