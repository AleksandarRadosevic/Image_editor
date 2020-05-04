#include "BasicOperation.h"
#include<algorithm>
void Add::operator()(std::vector<vectors_int> *vect, std::vector<Selection> s)
{
	std::cout << "Unesite argument za sabiranje" << std::endl;
	int arg0;
	std::cin >> arg0;
	bool active_selections = false;
	if (!s.empty())
	for (auto iter : s)
	{
		if (iter.is_active() == true)
		{
			active_selections = true;

			for (auto iter2 : iter)
			{
				int x = iter2.getx();
				int y = iter2.gety();
				int width = iter2.width();
				int height = iter2.height();
				int picture_width = iter.width();
				int picture_height = iter.height();
				for (int j = 0; j < height; j++)
				{
					for (int i = 3 * ((y+j)*(picture_width) + x); i < 3 * ((j+y)*(picture_width) + x + width); i++)
					{
						for (auto &vect_layer : (*vect))
						{
							vect_layer[i] = vect_layer[i] + arg0;
						}
					}
				
				}
			}

		}
	}
	if (active_selections == false)
	{
		for (auto &iter:*vect) {
			for (auto &iter2 : iter)
			{
				iter2 = iter2 + arg0;
			}	
		}

	}

}

void Sub::operator()(std::vector<vectors_int>* vect, std::vector<Selection> s)
{
	std::cout << "Unesite argument za oduzimanje" << std::endl;
	int arg0;
	std::cin >> arg0;
	bool active_selections = false;
	if (!s.empty())
		for (auto iter : s)
		{
			if (iter.is_active() == true)
			{
				active_selections = true;

				for (auto iter2 : iter)
				{
					int x = iter2.getx();
					int y = iter2.gety();
					int width = iter2.width();
					int height = iter2.height();
					int picture_width = iter.width();
					int picture_height = iter.height();
					for (int j = 0; j < height; j++)
					{
						for (int i = 3 * ((y + j)*(picture_width)+x); i < 3 * ((j + y)*(picture_width)+x + width); i++)
						{
							for (auto &vect_layer : (*vect))
							{
								vect_layer[i] = vect_layer[i] - arg0;
							}
						}

					}
				}

			}
		}
	if (active_selections == false)
	{
		for (auto &iter : *vect) {
			for (auto &iter2 : iter)
			{
				iter2 = iter2 - arg0;
			}
		}

	}

}


void Mul::operator()(std::vector<vectors_int>* vect, std::vector<Selection> s)
{
	std::cout << "Unesite argument za mnozenje" << std::endl;
	int arg0;
	std::cin >> arg0;
	bool active_selections = false;
	if (!s.empty())
		for (auto iter : s)
		{
			if (iter.is_active() == true)
			{
				active_selections = true;

				for (auto iter2 : iter)
				{
					int x = iter2.getx();
					int y = iter2.gety();
					int width = iter2.width();
					int height = iter2.height();
					int picture_width = iter.width();
					int picture_height = iter.height();
					for (int j = 0; j < height; j++)
					{
						for (int i = 3 * ((y + j)*(picture_width)+x); i < 3 * ((j + y)*(picture_width)+x + width); i++)
						{
							for (auto &vect_layer : (*vect))
							{
								vect_layer[i] = vect_layer[i] * arg0;
							}
						}

					}
				}

			}
		}
	if (active_selections == false)
	{
		for (auto &iter : *vect) {
			for (auto &iter2 : iter)
			{
				iter2 = iter2 * arg0;
			}
		}

	}

}

void Div::operator()(std::vector<vectors_int>* vect, std::vector<Selection> s)
{
	std::cout << "Unesite argument za deljenje" << std::endl;
	int arg0;
	std::cin >> arg0;
	bool active_selections = false;
	if (!s.empty())
		for (auto iter : s)
		{
			if (iter.is_active() == true)
			{
				active_selections = true;

				for (auto iter2 : iter)
				{
					int x = iter2.getx();
					int y = iter2.gety();
					int width = iter2.width();
					int height = iter2.height();
					int picture_width = iter.width();
					int picture_height = iter.height();
					for (int j = 0; j < height; j++)
					{
						for (int i = 3 * ((y + j)*(picture_width)+x); i < 3 * ((j + y)*(picture_width)+x + width); i++)
						{
							for (auto &vect_layer : (*vect))
							{
								vect_layer[i] = vect_layer[i] / arg0;
							}
						}

					}
				}

			}
		}
	if (active_selections == false)
	{
		for (auto &iter : *vect) {
			for (auto &iter2 : iter)
			{
				iter2 = iter2 / arg0;
			}
		}

	}

}

void Median::operator()(std::vector<vectors_int>* vect, std::vector<Selection> s)
{
	int picture_width = s[0].width();
	int picture_height = s[0].height();
	std::vector<vectors_int>copy_of_vector = *vect;
	bool active_selections = false;
	if (!s.empty())
		for (auto iter : s)
		{
			if (iter.is_active() == true)
			{
				active_selections = true;

				for (auto iter2 : iter)
				{
					int x = iter2.getx();
					int y = iter2.gety();
					int width = iter2.width();
					int height = iter2.height();
					
					for (int j = 0; j < height; j++)
					{
						for (int i = 3 * ((y + j)*(picture_width)+x); i < 3 * ((j + y)*(picture_width)+x + width); i++)
						{
							std::vector<vectors_int>::iterator copy = copy_of_vector.begin();
							for (auto &vect_layer : (*vect))
							{
								std::vector<int>arr;
								arr.push_back(vect_layer[i]);
								if (i - 4 >= 0)
								{
									arr.push_back(copy->operator[](i-4));
								}
								if (i + 4 < copy_of_vector.size())
								{
									arr.push_back(copy->operator[](i + 4));

								}
								if (i - 3 * picture_width >= 0)
								{
									arr.push_back(copy->operator[](i -3* picture_width));
								}
								if (i + 3 * picture_width < copy->size())
								{
									arr.push_back(copy->operator[](i + 3 * picture_width));
								}
								sort(arr.begin(), arr.end());
								int sr = arr.size() / 2;
								if (arr.size() % 2 == 1)
								{
									vect_layer[i] = arr[sr];
								}
								else
								{
									vect_layer[i] = (arr[sr] + arr[sr - 1]) / 2;
								}
								copy++;
							}
						}

					}
				}

			}
		}
	if (active_selections == false)
	{
		std::vector<vectors_int>::iterator copy = copy_of_vector.begin();
		int i = 0;
		for (auto iter = vect->begin(); iter != vect->end();iter++) {
			i = 0;
			for (auto iter2 = iter->begin();iter2!=iter->end();iter2++)
			{
				std::vector<int>arr;
				arr.push_back(*iter2);
				int old = *iter2;
				if (i - 4 >= 0)
				{
					arr.push_back(copy->operator[](i - 4));
				}
				if (i + 4 < copy->size())
				{
					arr.push_back(copy->operator[](i + 4));

				}
				if (i - 3 * picture_width >= 0)
				{
					arr.push_back(copy->operator[](i - 3 * picture_width));
				}
				if (i + 3 * picture_width < copy->size())
				{
					arr.push_back(copy->operator[](i + 3 * picture_width));
				}
				sort(arr.begin(), arr.end());
				int sr = arr.size() / 2;
				if (arr.size() % 2 == 1)
				{
					*iter2 = arr[sr];
				}
				else
				{
					*iter2 = (arr[sr] + arr[sr - 1]) / 2;
				}
				i++;
			}
			copy++;
		}

	}


}
