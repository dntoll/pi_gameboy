#include <iostream>
#include <stdlib.h>
#include "../../mcp3008/mcp3008.h"
#include "../../ili9341/src/ili9341.h"


using namespace std;


int map(int v, int fromMin, int fromMax, int toMin, int toMax) {
	float fromRange = fromMax-fromMin;
	float fromAt = (v-fromMin)/fromRange;
	float toRange = toMax-toMin;
	
	return toMin + (fromAt * toRange);
}

int main()
{
	
	ili9341 lcd;
	lcd.setBrightness(255);
	lcd.clearScreen();

	mcp3008 inst;

	lcd.fillBox(230, 310, 10, 10, rand()%255, rand()%255, rand()%255);
	
	while(true) {
		int x = inst.readValue(1);
		int y = inst.readValue(0);

		int vx = map(x, 0, 1024, 240, 0);
		int vy = map(x, 0, 1024, 240, 0);
		
		lcd.fillBox(vx, vy, 3, 3, rand()%255, rand()%255, rand()%255);
	}
	
	
	return 0;
}
