#pragma once

#include <string>
#include <GL/glew.h>


class Texture
{
public:
	Texture(GLenum TextureTarget, char* FileName);

	bool Load();

	void Bind(GLenum TextureUnit);

private:
	char* m_fileName;
	GLenum m_textureTarget;
	GLuint m_textureObj;


	int width, hight, channelnums; //图片宽和高，以及通道数
	unsigned char *data;	//图像像素数据

}; 

