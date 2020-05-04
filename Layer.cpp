#include "Layer.h"
#include<windows.h>
Layer::Layer(int w, int h, int o, bool act, bool vis)
{
	width_ = w;
	height_ = h;
	opacity_ = o;
	active_ = act;
	visible_ = vis;
}

Layer::Layer(const Layer &l)
{
	width_ = l.width_;
	height_ = l.height_;
	opacity_= l.opacity_;
	active_ = l.active_;
	vector_ = l.vector_;
}

Layer::Layer(std::string s)
{

}

void Layer::Draw()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	int i = 0;
	int x, y;
	x = 0;
	y = 0;
	for (auto p : vector_)
	{
		x++;
		COLORREF COLOR = RGB(p.red(), p.green(), p.blue());
		SetPixel(mydc, x, y, COLOR);
		if (x == width_) {
			x = 0;
			y++;
		}
	}
	ReleaseDC(myconsole, mydc);
	std::cin.ignore();
}

void Layer::Delete_layer()
{
	width_ = height_ = opacity_ = 0;
	active_ = visible_ = false;
	vector_.clear();
}
