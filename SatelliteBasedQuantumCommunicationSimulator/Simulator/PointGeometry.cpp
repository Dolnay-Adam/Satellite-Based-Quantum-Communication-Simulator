#include "PointGeometry.h"


PointGeometry::PointGeometry()
{
	vao.Bind();
	std::vector<vec3> position;
	position.emplace_back(0.f, 0.f, 0.f);
	VBO vbo(position);

	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 0, nullptr);
	vao.Unbind();
	vbo.Unbind();
}

void PointGeometry::draw()
{
	glPointSize(4.f);
	vao.Bind();
	glDrawArrays(GL_POINTS, 0, 1);
	vao.Unbind();
	glPointSize(1.0f);
}
