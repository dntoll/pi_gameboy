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

	lcd.fillBox(240, 320, 10, 10, rand()%255, rand()%255, rand()%255);
	
	while(true) {
		int x = 1024-inst.readValue(1);
		int y = 1024-inst.readValue(0);
		
		lcd.fillBox(x/4, y/4, 3, 3, rand()%255, rand()%255, rand()%255);
	}
	
	
	return 0;
}
