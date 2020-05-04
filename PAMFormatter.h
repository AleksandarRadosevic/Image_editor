#pragma once
#include"Formatter.h"

class PAMFormatter :public Formmater {
public:
	PAMFormatter(std::string filename) {
		int i;
		filename = "D:\\Desktop\\2.pam";
		FILE* f = fopen(filename.c_str(), "rb");
		unsigned char *data = new unsigned char[1];
		fread(data, sizeof(unsigned char), 1, f);
		while (*data!=' ')
		{
			fread(data, sizeof(unsigned char), 1, f);
		}
		int width=0,height=0;
		fread(data, sizeof(unsigned char), 1, f);
		while (*data != '\n')
		{
			
			int val = *data - '0';
			width =width*10 + val;
			fread(data, sizeof(unsigned char), 1, f);

		}
		while (*data != ' ')
		{
			fread(data, sizeof(unsigned char), 1, f);
		}
		fread(data, sizeof(unsigned char), 1, f);
		while (*data != '\n')
		{
			
			int val = *data - '0';
			height = height*10 + val;
			fread(data, sizeof(unsigned char), 1, f);

		}
		fread(data, sizeof(unsigned char), 1, f);
		int cnt = 0;
		while (cnt < 4)
		{
			fread(data, sizeof(unsigned char), 1, f);
			if (*data == '\n')
			{
				cnt++;
			}
		}
		Layer l(width,height,100,1,1);
		for (int i = 0; i < width*height;i++) {
				fread(data, sizeof(unsigned char), 1, f);
				int red = *data;
				fread(data, sizeof(unsigned char), 1, f);
				int green = *data;
				fread(data, sizeof(unsigned char), 1, f);
				int blue = *data;
				fread(data, sizeof(unsigned char), 1, f);
				int alpha = *data;
				Pixel p1(red, green, blue, alpha);
				l.push_back(p1);
		}
		fclose(f);
		layers.push_back(l);

	}


	void Read(std::string filename) {
		int i;
		filename = "D:\\Desktop\\2.pam";
		FILE* f = fopen(filename.c_str(), "rb");
		unsigned char *data = new unsigned char[1];
		fread(data, sizeof(unsigned char), 1, f);
		while (*data != ' ')
		{
			fread(data, sizeof(unsigned char), 1, f);
		}
		int width = 0, height = 0;
		fread(data, sizeof(unsigned char), 1, f);
		while (*data != '\n')
		{

			int val = *data - '0';
			width = width * 10 + val;
			fread(data, sizeof(unsigned char), 1, f);

		}
		while (*data != ' ')
		{
			fread(data, sizeof(unsigned char), 1, f);
		}
		fread(data, sizeof(unsigned char), 1, f);
		while (*data != '\n')
		{

			int val = *data - '0';
			height = height * 10 + val;
			fread(data, sizeof(unsigned char), 1, f);

		}
		fread(data, sizeof(unsigned char), 1, f);
		int cnt = 0;
		while (cnt < 4)
		{
			fread(data, sizeof(unsigned char), 1, f);
			if (*data == '\n')
			{
				cnt++;
			}
		}
		Layer l(width, height, 100, 1, 1);
		for (int i = 0; i < width*height; i++) {
			fread(data, sizeof(unsigned char), 1, f);
			int red = *data;
			fread(data, sizeof(unsigned char), 1, f);
			int green = *data;
			fread(data, sizeof(unsigned char), 1, f);
			int blue = *data;
			fread(data, sizeof(unsigned char), 1, f);
			int alpha = *data;
			Pixel p1(red, green, blue, alpha);
			l.push_back(p1);
		}
		fclose(f);
		layers.push_back(l);

	}


};