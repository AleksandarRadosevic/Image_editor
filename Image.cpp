#include "Image.h"
#include<algorithm>
Image::Image(int w, int h)
{
	width_ = w;
	height_ = h;
}

Image::Image(Formmater * f)
{
	this->f = f;
	for (auto a: *f)
	{
		Add_layer(a);
	}
}

void Image::Add_layer(const Layer &l)
{

	Layer copy_layer = l;
	//if ()

	layers.push_back(l);


}

void Image::Add_selection(const Selection &p)
{
	Selection s = p;
	if (s.width() == 0)
	{
		s.set_picture_width(width_);
		s.set_picture_height(height_);
	}
	selections.push_back(s);

}

void Image::Execute_all_operations()
{
	
	std::vector<vectors_int>*vector_for_execution = new std::vector<vectors_int>;
	
	Create_vector(vector_for_execution);
	for_each(operations.begin(), operations.end(), [this, &vector_for_execution](Operation *operation) {
		operation->operator()(vector_for_execution, this->selections);
	});

	Return_vector(vector_for_execution);
}

void Image::Create_vector(std::vector<vectors_int>*v)
{

	for (auto iter : layers)
	{
		vectors_int v1;
		for (auto iter2 : iter)
		{
			v1.push_back(iter2.red());
			v1.push_back(iter2.green());
			v1.push_back(iter2.blue());
		//	v1.push_back(iter2.alpha());	alpha se ne menja
		}
		v->push_back(v1);
	}

	Add_inactive_selection();
}

void Image::Return_vector(std::vector<vectors_int>*v)
{
	std::vector<Layer>::iterator temp_layer = layers.begin();
	for (auto iter:*v){
		int i = 0;
		for (auto iter2 = iter.begin(); iter2 != iter.end();iter2)
		{
			temp_layer->operator[](i).set_red(*iter2++);
			temp_layer->operator[](i).set_green(*iter2++);
			temp_layer->operator[](i).set_blue(*iter2++);
			i++;
		//	temp_layer->operator[](i).set_alpha(*iter2++); alpha se ne menja
		}
		temp_layer++;
	}



}


Layer Image::Compress_in_one_layer()
{
	Layer comp = *(layers.begin());
	int i = 0;
	for (auto &temp : layers)
	{
		if (i > 0)
		{
			int j = 0;
			for (auto &iter : temp)
			{
				comp[j].set_red((uint8_t)((float)temp.opacity() / 100 * iter.red() + (1 - ((float)temp.opacity() / 100)*((float)iter.alpha()) / 255)*comp[j].red()));
				comp[j].set_green((uint8_t)((float)temp.opacity() / 100 * iter.green() + (1 - ((float)temp.opacity() / 100)*((float)iter.alpha()) / 255)*comp[j].green()));
				comp[j].set_blue((uint8_t)((float)temp.opacity() / 100 * iter.blue() + (1 - ((float)temp.opacity() / 100)*((float)iter.alpha()) / 255)*comp[j].blue()));

			}
		}
		i++;
	}
	return comp;
}

void Image::Draw()
{
	Layer l = Compress_in_one_layer();
	l.Draw();

}
void Image::Add_inactive_selection()
{
	Rectangle1 rec(0, 0, 0, 0);
	std::vector<Rectangle1>sel;
	Selection s("prazna selekcija", sel, false);
	s.set_picture_width(width_);
	s.set_picture_height(height_);
	Add_selection(s);
}