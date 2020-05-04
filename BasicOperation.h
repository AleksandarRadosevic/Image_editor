#pragma once
#include"Operation.h"


class Add :public Operation {
public:
	Add() :Operation("add") {}
	void operator()(std::vector<vectors_int>*vect, std::vector<Selection>s);
private:
};

class Sub :public Operation {
public:
	Sub() :Operation("sub") {}
	void operator()(std::vector<vectors_int>*vect, std::vector<Selection>s);

};

class Mul :public Operation {
public:
	Mul() :Operation("sub") {}
	void operator()(std::vector<vectors_int>*vect, std::vector<Selection>s);

};

class Div :public Operation {
public:
	Div() :Operation("sub") {}
	void operator()(std::vector<vectors_int>*vect, std::vector<Selection>s);

};

class Median :public Operation {
public:
	Median():Operation("median"){}
	void operator()(std::vector<vectors_int>*vect, std::vector<Selection>s);
};