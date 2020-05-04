#pragma once
#include"Operation.h"

class CompositeOperation :public Operation {
public:
	CompositeOperation(std::string name):Operation(name){}
	void Add_operation(Operation*);
	void operator()(std::vector<vectors_int>*, std::vector<Selection>);

private:
	std::vector<Operation*>operations_in_composite;
};