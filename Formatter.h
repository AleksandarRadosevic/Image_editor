#pragma once
#include"Layer.h"
#include<regex>
class Formmater {
public:
	virtual void Read(std::string) = 0;
	Layer& operator[](int i) { return layers[i]; }
	std::vector<Layer>::iterator begin() { return layers.begin(); }
	std::vector<Layer>::iterator end() { return layers.end(); }

protected:
	std::vector<Layer>layers;
};