#pragma once

#include <GL/Glew.h>
#include <vector>
#include "LinAlg.h"

class VBO
{
public:
	explicit VBO(std::vector<vec2> vertices);
	explicit VBO(std::vector<vec3> vertices);
	explicit VBO(std::vector<vec4> vertices);
	explicit VBO(std::vector<float> vertices);

	void Bind();
	void Unbind();
	void Delete();
	
private:
	GLuint ID;
};

