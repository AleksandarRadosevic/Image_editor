#pragma once
#include"Layer.h"
#include"Formatter.h"
#include"Selection.h"
#include"Operation.h"
#include"int_vectors.h"
class Image {
public:
	Image(int,int);
	Image(Formmater *f);
	void Add_layer(const Layer &l);
	void Add_selection(const Selection&);
	void Add_operation(Operation*op) { operations.push_back(op); }
	void Execute_all_operations();
	Layer Compress_in_one_layer();

	void Draw();
private:
	int depth;
	Formmater *f;
	int width_;
	int height_;
	std::vector<Layer>layers;
	std::vector<Selection>selections;
	std::vector<Operation*>operations;

	void Create_vector(std::vector<vectors_int>*);
	void Return_vector(std::vector<vectors_int>*);
	void Add_inactive_selection();
};


