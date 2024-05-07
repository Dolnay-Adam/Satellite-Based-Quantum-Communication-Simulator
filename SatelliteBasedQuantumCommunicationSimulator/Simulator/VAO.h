#pragma once

#include <GL/Glew.h>
#include <vector>
#include "LinAlg.h"
#include "VBO.h"

class VAO
{
public:
	GLuint ID;

	VAO();

	void LinkAttrib(VBO& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void Bind();

	void Unbind();

	void Delete();

};

