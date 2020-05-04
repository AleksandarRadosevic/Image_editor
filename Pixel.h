#pragma once
#include<iostream>

class Pixel {
public:

	Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		red_ = r;
		blue_ = b;
		green_ = g;
		alpha_ = a;
	}
	uint8_t red() { return red_; }
	uint8_t green() { return green_; }
	uint8_t blue() { return blue_; }
	uint8_t alpha() { return alpha_; }
	void set_red(uint8_t r) { red_ = r; }
	void set_green(uint8_t r) { green_ = r; }
	void set_blue(uint8_t r) { blue_ = r; }
	void set_alpha(uint8_t r) { alpha_ = r; }


private:
	uint8_t red_;
	uint8_t green_;
	uint8_t blue_;
	uint8_t alpha_;

};