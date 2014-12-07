#pragma once

class Ball {
	public:
		Ball();

		void update(float dt);

		float getX() const;
		float getY() const;
	private:
		float x;
		float y;
		float dx;
		float dy;
};

