#pragma once
class Rectangle1 {

public:
	Rectangle1(int xx, int yy, int w, int h) {
		x = xx;
		y = yy;
		width_ = w;
		height_ = h;
	}
	int getx()const { return x; }
	int gety()const { return y; }
	int width()const { return width_; }
	int height()const { return height_; }
	void setx(int xx) { x = xx; }
	void sety(int yy) { y = yy; }
	void set_width(int w) { width_=w; }
	void set_height(int h) { height_ = h; }

	private:
		int x;
		int y;
		int width_;
		int height_;
};