#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

int main(){

	int width, hight, channelnums; //ͼƬ��͸ߣ��Լ�ͨ����
	unsigned char *data;	//ͼ����������

	data = stbi_load("data/test.png", &width, &hight, &channelnums, 0);
	if (data == nullptr){
		std::cerr << "Reading Texture failed!";
		return false;
	}

	return 0;
}