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
	bool xvalues[1024];
	bool yvalues[1024];
	for (int i = 0; i< 1024; i++) {
		xvalues[i] = false;
		yvalues[i] = false;
	}

	ili9341 lcd;
	lcd.setBrightness(255);
	lcd.clearScreen();

	mcp3008 inst;

	lcd.fillBox(230, 310, 10, 10, rand()%255, rand()%255, rand()%255);
	int b;
	do {
		int x = inst.readValue(1);
		int y = inst.readValue(0);
		b = inst.readValue(2);

		xvalues[x] = true;
		xvalues[y] = true;

		int vx = map(x, 0, 1024, 230, 10);
		int vy = map(y, 0, 1024, 310, 10);
		
		lcd.fillBox(vx, vy, 3, 3, rand()%255, rand()%255, rand()%255);

		cout << x << " : " << y << "\n";
	} while (b < 1000);
	lcd.clearScreen();
	
	
	return 0;
}
