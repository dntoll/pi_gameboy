#pragma once

#include "../../ili9341/src/ili9341.h"
#include "PongModel.h"

class PongView {
	public:
		PongView(const PongModel &m, ili9341 &lcd);
		void draw();
	private:
		int map(int v, int fromMin, int fromMax, int toMin, int toMax);

		const PongModel &model;
		ili9341 &screen;

		int ovx, ovy;
};

