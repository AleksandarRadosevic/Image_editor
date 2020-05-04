#pragma once
#include<vector>

class vectors_int {
public:
	int& operator[](int i) { return vector_[i]; }
	std::vector<int>::iterator begin() {return vector_.begin(); }
	std::vector<int>::iterator end() { return vector_.end(); }
	void push_back(int a) { vector_.push_back(a); }
	void pop_back() { vector_.pop_back(); }
	int size()const { return vector_.size(); }


private:
	std::vector<int>vector_;
	
};