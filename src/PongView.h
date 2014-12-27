#pragma once

#include "../../ili9341/src/BackBuffer.h"
#include "PongModel.h"

class PongView {
	public:
		PongView(const PongModel &m, BackBuffer &lcd);

		void draw();

	private:

		int map(int v, int fromMin, int fromMax, int toMin, int toMax);

		const PongModel &model;

		BackBuffer &screen;
		//old x old y to avoid redrawing the screen
		int ovx, ovy;
};

