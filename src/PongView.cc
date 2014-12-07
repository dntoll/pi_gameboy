#include "PongView.h"

PongView::PongView(const PongModel &m, ili9341 &lcd) : model(m), screen(lcd) {
	
}