#include <iostream>
#include <stdlib.h>
#include "../../mcp3008/mcp3008.h"
#include "../../ili9341/src/ili9341.h"


using namespace std;

int main()
{
	
	ili9341 lcd;
	lcd.setBrightness(255);
	lcd.clearScreen();

	mcp3008 inst;

	lcd.fillBox(0, 0, 10, 10, rand()%255, rand()%255, rand()%255);
	
	while(true) {
		int x = inst.readValue(0);
		int y = inst.readValue(1);
		lcd.fillBox(x/4, y/4, 50, 50, rand()%255, rand()%255, rand()%255);
	}
	
	
	return 0;
}
