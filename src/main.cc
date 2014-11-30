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
	
	for (int i = 0;i < 1000; i++) {
		for (int c = 0; c < 8; c++) {
			int value = inst.readValue(c);
			cout << " [" << value << "]";	
		}
		cout << "\n";	
	
	}
	
	
	return 0;
}
