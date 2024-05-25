#pragma once

#include "Texture.h"
#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>


class FullScreenTexture : public Texture 
{
public:
	explicit FullScreenTexture(std::string filePath);

	void Bind() const override;
	void UnBind() const override;

	~FullScreenTexture() final;
private:
	unsigned int ID;
};

