#pragma once
#include"Rectangle.h"
#include<iostream>
#include<vector>
class Selection {
public:
	Selection(std::string n, std::vector<Rectangle1>vect,bool act=true) {
		name = n;
		vector_ = vect;
		active_ = act;
		picture_width = picture_height = 0;
	}
	std::vector<Rectangle1>::iterator begin() { return vector_.begin(); }
	std::vector<Rectangle1>::iterator end() { return vector_.end(); }
	void Delete_selection();
	bool is_active() const { return active_; }
	std::string get_name()const { return name; }
	void set_active(bool t) { active_ = t; }
	void set_picture_width(int w) { picture_width = w; }
	void set_picture_height(int h) { picture_height = h; }
	int width()const { return picture_width; }
	int height()const { return picture_height; }

private:
	bool active_;
	std::string name;
	std::vector<Rectangle1>vector_;
	int picture_width;
	int picture_height;
};