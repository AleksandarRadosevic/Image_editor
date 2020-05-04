#pragma once
#include<vector>
#include"Pixel.h"
class Layer
{
public:
	Layer(int, int, int, bool, bool);
	Layer(const Layer&);
	Layer(std::string);
	
	std::vector<Pixel>::iterator begin() { return vector_.begin(); }
	std::vector<Pixel>::iterator end() { return vector_.end(); }
	int width()const { return width_; }
	int height()const { return height_; }
	int opacity()const { return opacity_; }
	int size() const{ return width_ * height_; }
	bool active() const { return active_; }
	bool visible()const { return visible_; }
	Pixel &operator[](int i) { return vector_[i]; }
	
	void set_width(int w) {  width_=w; }
	void set_height(int h) {  height_=h; }
	void set_opacity(int op) {  opacity_=op; }
	void set_active(bool vr)  {  active_=vr; }
	void set_visible(bool vr) {  visible_=vr; }
	void push_back(Pixel p) { vector_.push_back(p); }
	void pop_back() { vector_.pop_back(); }
	
	
	void Draw();
	void Delete_layer();


private:
	bool active_;
	bool visible_;
	int height_;
	int width_;
	int opacity_;
	std::vector<Pixel>vector_;
};