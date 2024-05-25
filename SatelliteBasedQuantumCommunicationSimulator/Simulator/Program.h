#pragma once

#include <string>
#include <glad/glad.h>
#include "Shader.h"
#include "LinAlg.h"

class Program
{
public:
	Program();
	~Program();

	void Bind();
	void Unbind();

	Program& AttachShader(const unsigned int shaderID);
	Program& LinkProgram();
	
	bool SetUniform(const vec2& v, const std::string& name);
	bool SetUniform(int i, const std::string& name);
	bool SetUniform(mat4& m, const std::string& name);

private:
	unsigned int ID;
	int GetUniformLocation(const std::string& name);
};

