#pragma once

#include "PongModel.h"
#include "PongView.h"

class PongController {
	public:
		PongController(PongModel &m, PongView &v);

	private:
		PongModel &model;
		PongView &view;
};

