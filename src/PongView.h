#pragma once

#include "PongModel.h"

class PongView {
	public:
		PongView(const PongModel &m, ili9341 &lcd);

	private:
		const PongModel &model;
		ili9341 &screen;
};

