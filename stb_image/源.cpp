#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

int main(){

	int width, hight, channelnums; //图片宽和高，以及通道数
	unsigned char *data;	//图像像素数据

	data = stbi_load("data/test.png", &width, &hight, &channelnums, 0);
	if (data == nullptr){
		std::cerr << "Reading Texture failed!";
		return false;
	}

	return 0;
}