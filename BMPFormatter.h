#pragma once
#include"Formatter.h"
#include<string>
class BMPFormatter :public Formmater {
public:
	BMPFormatter(std::string filename) {
		int i;
		FILE* f = fopen(filename.c_str(), "rb");
		unsigned char info[122];

		// read the 122-byte header
		fread(info, sizeof(unsigned char), 122, f);

		// extract image height and width from header
		int width = *(int*)&info[18];
		int height = *(int*)&info[22];

		// allocate 4 bytes per pixel
		int size = 4 * width * height;
		//unsigned char* data = new unsigned char[size];
		unsigned char *data = new unsigned char[size];
		// read the rest of the data at once
		fread(data, sizeof(unsigned char), size, f);
		fclose(f);

		for (i = 0; i < size; i += 4)
		{
			// flip the order of every 3 bytes
			unsigned char tmp = data[i];
			data[i] = data[i + 2];
			data[i + 2] = tmp;
		}

		Layer l(width, height, 100, 1, 1);
		for (i=height-1;i>=0;i--)
			for (int j = 0; j <width; j++)
			{
				int red = data[4 * (i*width + j)];
				int green = data[4 * (i*width + j)+1];
				int blue = data[4 * (i*width + j)+2];
				int alpha = data[4 * (i*width + j) + 3];
				Pixel p1(red, green, blue, alpha);
				l.push_back(p1);
			}
			
		layers.push_back(l);
		
	}

	

	void Read(std::string filename) {
		int i;
		filename = "D:\Desktop\\1.bmp";
		FILE* f = fopen(filename.c_str(), "rb");
		unsigned char info[122];

		// read the 122-byte header
		fread(info, sizeof(unsigned char), 122, f);

		// extract image height and width from header
		int width = *(int*)&info[18];
		int height = *(int*)&info[22];

		// allocate 4 bytes per pixel
		int size = 4 * width * height;
		unsigned char* data = new unsigned char[size];

		// read the rest of the data at once
		fread(data, sizeof(unsigned char), size, f);
		fclose(f);

		for (i = 0; i < size; i += 4)
		{
			// flip the order of every 3 bytes
			unsigned char tmp = data[i];
			data[i] = data[i + 2];
			data[i + 2] = tmp;
		}

		Layer l(width, height, 100, 1, 1);
		for (int i = 0; i < size;i+=4)
		{
			int red = data[i];
			int blue = data[i + 1];
			int green = data[i + 2];
			int alpha = data[i + 3];
			Pixel p1(red, blue, green, alpha);
			l.push_back(p1);
		}
		
	}
	

};