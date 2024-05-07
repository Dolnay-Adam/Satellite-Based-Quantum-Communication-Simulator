#include "Material.h"

Material::Material(std::shared_ptr<Program> program) : m_program(program) {}

void Material::bindProgram() const
{
	m_program->Bind();
}

void Material::unbindProgram() const
{
	m_program->Unbind();
}

void Material::SetMatrix(mat4 M, const std::string name)
{
	m_program->SetUniform(M, name);
}

Material& Material::addTexture(const std::shared_ptr<Texture> texture, const std::string name)
{
	m_textures[name] = texture;
	return *this;
}

void Material::draw()
{
	for (auto i : m_uniforms) {
		i.second->commit(*m_program.get());
	}
	for (auto i : m_textures) {
		i.second->Bind();
	}
}


