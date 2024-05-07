#pragma once

#include <memory>
#include "Program.h"
#include "Texture.h"
#include "Uniform.h"
#include "LinAlg.h"
#include <unordered_map>

class Material
{
public:
	Material(std::shared_ptr<Program> program);

	void bindProgram() const;
	void unbindProgram() const;

	void SetMatrix(mat4 M, const std::string name);
	Material& addTexture(const std::shared_ptr<Texture> texture, const std::string name);


	void draw();

private:
	std::shared_ptr<Program> m_program;
	std::unordered_map<std::string, std::shared_ptr<Uniform>> m_uniforms;
	std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
};

