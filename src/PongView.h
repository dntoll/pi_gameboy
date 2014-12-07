#pragma once

#include "PongModel.h"

class PongView {
	public:
		PongView(const PongModel &m);

	private:
		const PongModel &model;
};

