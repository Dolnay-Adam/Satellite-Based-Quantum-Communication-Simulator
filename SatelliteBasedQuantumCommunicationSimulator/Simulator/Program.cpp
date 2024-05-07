#include "Program.h"
#include <iostream>

Program::Program()
{
	ID = glCreateProgram();
}

Program::~Program()
{
	glDeleteProgram(ID);
}

void Program::Bind()
{
	glUseProgram(ID);
}

void Program::Unbind()
{
	glUseProgram(0);
}

Program& Program::AttachShader(const unsigned int shaderID)
{
	glAttachShader(ID, shaderID);
	return *this;
}

Program& Program::LinkProgram()
{
	glLinkProgram(ID);

	glValidateProgram(ID);
	GLint result;
	glGetProgramiv(ID, GL_VALIDATE_STATUS, &result);
	if (result != GL_TRUE)
		std::cout << "Program is not valid" << std::endl;

	return *this;
}

bool Program::SetUniform(const vec2& v, const std::string& name)
{
	int location = GetUniformLocation(name);
	if (location >= 0)
		glUniform2f(location, v.x, v.y);

	return location >= 0;
}

bool Program::SetUniform(int i, const std::string& name)
{
	int location = GetUniformLocation(name);
	if (location >= 0) {
		glUniform1i(location, i);
	}
	return false;
}

bool Program::SetUniform(mat4& m, const std::string& name)
{
	int location = GetUniformLocation(name);
	if (location >= 0) {
		glUniformMatrix4fv(location, 1, GL_TRUE, m.getValuePtr());
	}
	return false;
}

int Program::GetUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(ID, name.c_str());
	if (location < 0)
		std::cout << "Error: uniform" << name.c_str() << " cannot be set" << std::endl;

	return location;
}
