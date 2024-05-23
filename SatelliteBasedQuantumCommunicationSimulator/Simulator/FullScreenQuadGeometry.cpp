#include "FullScreenQuadGeometry.h"

FullScreenQuadGeometry::FullScreenQuadGeometry()
{
	vao.Bind();
	std::vector<vec3> positions = {
		vec3(-1.f, -1.f, 1.0f),
		vec3(-1.f, 1.f, 1.0f),
		vec3(1.f, -1.f, 1.0f),
		vec3(1.f, 1.f, 1.0f)
	};

	std::vector<vec2> texCoords = {
		vec2(0.f, 1.f),
		vec2(0.f, 0.f),
		vec2(1.f, 1.f),
		vec2(1.f, 0.f)
	};

	VBO posVBO(positions);
	VBO texVBO(texCoords);

	vao.LinkAttrib(posVBO, 0, 3, GL_FLOAT, 0, nullptr);
	vao.LinkAttrib(texVBO, 1, 2, GL_FLOAT, 0, nullptr);

	vao.Unbind();
	posVBO.Unbind();
	texVBO.Unbind();
}

void FullScreenQuadGeometry::draw()
{
	vao.Bind();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
