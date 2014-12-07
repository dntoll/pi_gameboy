#pragma once

#include "../../mcp3008/mcp3008.h"


class JoyStick {
	public:
		JoyStick();
		~JoyStick();

		int getX();
		int getY();

	private:

		int map(int v, int fromMin, int fromMax, int toMin, int toMax);
		float removeBlindSpot(int value);
		//Some input values are missing so this buffer contains the working values	
		bool values[1024];

		//The ADC
		mcp3008 inst;
};
