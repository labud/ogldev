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


	int width, hight, channelnums; //ͼƬ��͸ߣ��Լ�ͨ����
	unsigned char *data;	//ͼ����������

}; 

