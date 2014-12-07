#include "joystick.h"

JoyStick::JoyStick() {
	for (int i = 0; i< 1024; i++) {
		values[i] = false;
	}

	FILE * pFile;
	pFile = fopen ("joystick.bin", "rb");
	fread (values , sizeof(bool), sizeof(values), pFile);
	fclose (pFile);
}

JoyStick::~JoyStick() {
	
	FILE *pFile = fopen ("joystick.bin", "wb");
	fwrite (values , sizeof(bool), sizeof(values), pFile);
	fclose (pFile);
}


int JoyStick::getX() {
	int x = inst.readValue(1);
	
	if (values[x] == false) {
		values[x] = true;
	}
		
	return removeBlindSpot(x) * 1024.0f;
}

int JoyStick::getY() {
	int x = inst.readValue(0);
	
	if (values[x] == false) {
		values[x] = true;
	}
		
	return removeBlindSpot(x) * 1024.0f;
}

bool JoyStick::buttonDown() {
	return inst.readValue(2) > 500;
}

float JoyStick::removeBlindSpot(int value) {
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
