#pragma once



class PongController {
	public:
		PongController(PongModel &m, PongView &v);

	private:
		PongModel &model;
		PongView &view;
};

