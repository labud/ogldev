#include "Texture.h"

#include <iostream>
#include <exception>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(GLenum TextureTarget, char* FileName)
{
	m_textureTarget = TextureTarget;
	m_fileName = FileName;
}



bool Texture::Load()
{
	data = stbi_load(m_fileName, &width, &hight, &channelnums, 0);
	if (data == nullptr){
		std::cerr << "Reading Texture failed!";
		return false;
	}

	glGenTextures(1, &m_textureObj);
	glBindTexture(m_textureTarget, m_textureObj);
	glTexImage2D(m_textureTarget, 0, GL_RGBA, width, hight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(m_textureTarget, 0);

	return true;
}

void Texture::Bind(GLenum TextureUnit)
{
	glActiveTexture(TextureUnit);
	glBindTexture(m_textureTarget, m_textureObj);
}
