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
	
	for (int i = 0;i < 1000; i++) {
		for (int c = 0; c < 8; c++) {
			int value = inst.readValue(c);
			cout << " [" << value << "]";	
			//lcd.fillBox(0, 5, value/4, 50, rand()%255, rand()%255, rand()%255);
		}
		cout << "\n";	
		sleep(1);
	
	}
	
	
	return 0;
}
