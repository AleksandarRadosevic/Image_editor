#include "CompositeOperation.h"

void CompositeOperation::Add_operation(Operation *op)
{
	operations_in_composite.push_back(op);
}

void CompositeOperation::operator()(std::vector<vectors_int>*vect, std::vector<Selection>sel)
{
	for (auto &p : operations_in_composite)
	{
		p->operator()(vect, sel);
	}

}
