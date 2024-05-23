#include "CubeGeometry.h"

CubeGeometry::CubeGeometry()
{
	vao.Bind();
	std::vector<vec3> vertices = {
		vec3(-1.0f, -1.0f, -1.0f), vec3(-1.0f, -1.0f, 1.0f), vec3(-1.0f, 1.0f, -1.0f),
		vec3(-1.0f, 1.0f, -1.0f), vec3(-1.0f, 1.0f, 1.0f), vec3(-1.0f, -1.0f, 1.0f),

		vec3(-1.0f, -1.0f, -1.0f), vec3(1.0f, -1.0f, -1.0f), vec3(-1.0f, 1.0f, -1.0f),
		vec3(-1.0f, 1.0f, -1.0f), vec3(1.0f, 1.0f, -1.0f), vec3(1.0f, -1.0f, -1.0f),

		vec3(1.0f, -1.0f, -1.0f), vec3(1.0f, -1.0f, 1.0f), vec3(1.0f, 1.0f, -1.0f),
		vec3(1.0f, 1.0f, -1.0f), vec3(1.0f, 1.0f, 1.0f), vec3(1.0f, -1.0f, 1.0f),

		vec3(-1.0f, -1.0f, 1.0f), vec3(1.0f, -1.0f, 1.0f), vec3(-1.0f, 1.0f, 1.0f),
		vec3(-1.0f, 1.0f, 1.0f), vec3(1.0f, 1.0f, 1.0f), vec3(1.0f, -1.0f, 1.0f),

		vec3(-1.0f, -1.0f, -1.0f), vec3(-1.0f, -1.0f, 1.0f), vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f, -1.0f, -1.0f), vec3(1.0f, -1.0f, 1.0f), vec3(-1.0f, -1.0f, 1.0f),

		vec3(-1.0f, 1.0f, -1.0f), vec3(-1.0f, 1.0f, 1.0f), vec3(1.0f, 1.0f, -1.0f),
		vec3(1.0f, 1.0f, -1.0f), vec3(1.0f, 1.0f, 1.0f), vec3(-1.0f, 1.0f, 1.0f)
	};

	VBO vbo(vertices);

	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 0, nullptr);
	vao.Unbind();
	vbo.Unbind();
}

void CubeGeometry::draw()
{
	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	vao.Unbind();
}
