#include <iostream>
#include <stdlib.h>
#include "../../mcp3008/mcp3008.h"
#include "../../ili9341/src/ili9341.h"
#include <stdio.h>

using namespace std;



int map(int v, int fromMin, int fromMax, int toMin, int toMax) {
	float fromRange = fromMax-fromMin;
	float fromAt = (v-fromMin)/fromRange;
	float toRange = toMax-toMin;
	
	return toMin + (fromAt * toRange);
}


bool values[1024];

float removeBlindSpot(int value) {
	values[value] = true;
	
	int numValues = 0;
	int numValuesLower = 0;
	for (int i = 0; i< 1024; i++) {
		if (values[i]) {
			numValues++;
			if ( i < value) {
				numValuesLower++;
			}
		}
	}
	
	
	return (float)numValuesLower / (float)numValues;

	
}

int main()
{
	
	for (int i = 0; i< 1024; i++) {
		values[i] = false;
	}
	FILE * pFile;
	pFile = fopen ("joystick.bin", "rb");
	fread (values , sizeof(bool), sizeof(values), pFile);
	fclose (pFile);

	ili9341 lcd;
	lcd.setBrightness(255);
	lcd.clearScreen();

	mcp3008 inst;

	lcd.fillBox(230, 310, 10, 10, rand()%255, rand()%255, rand()%255);
	int b;
	
	do {
		//It seems that the joystick has some blind zones, jumping from one interval to another
		//calibration collects all values that are achieved
		bool foundNewValues = false;
		int x = inst.readValue(1);
		int y = inst.readValue(0);
		b = inst.readValue(2);
		
		if (values[x] == false || values[y] == false) {
			values[x] = true;
			foundNewValues = true;
		}
		
		float fx = removeBlindSpot(x) * 1024.0f;
		float fy = removeBlindSpot(y) * 1024.0f;

		int vx = map(fx, 0, 1024, 230, 10);
		int vy = map(fy, 0, 1024, 310, 10);
		//lcd.clearScreen();
		lcd.fillBox(vx, vy, 3, 3, rand()%255, rand()%255, rand()%255);
		
	} while (b > 500);

	lcd.clearScreen();
	
	pFile;
	pFile = fopen ("joystick.bin", "wb");
	fwrite (values , sizeof(bool), sizeof(values), pFile);
	fclose (pFile);
	
	return 0;
}
