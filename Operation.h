#pragma once
#include<vector>
#include<string>
#include"int_vectors.h"
#include"Selection.h"
class Operation {
public:

	Operation(std::string n) {
		name = n;
	}

	virtual void operator()(std::vector<vectors_int>*, std::vector<Selection>) = 0;


protected:
	std::string name;
	std::vector<int>arguments;
};