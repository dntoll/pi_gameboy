#pragma once

#include "../../ili9341/src/ili9341.h"
#include "PongModel.h"

class PongView {
	public:
		PongView(const PongModel &m, ili9341 &lcd);
		void draw();
	private:
		const PongModel &model;
		ili9341 &screen;
};

