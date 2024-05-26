#include "GlobeScene.h"

GlobeScene::GlobeScene() : Scene() {}

void GlobeScene::build()
{
	//Globe
	GLuint basicVS = CreateShader(GL_VERTEX_SHADER, "BasicVS.glsl");
	GLuint basicFS = CreateShader(GL_FRAGMENT_SHADER, "BasicFS.glsl");

	auto basicProgram = std::make_shared<Program>();
	basicProgram->AttachShader(basicVS).AttachShader(basicFS).LinkProgram();
	auto basicMaterial = std::make_shared<Material>(basicProgram);

	std::shared_ptr<Geometry> cubeGeometry = std::make_shared<CubeGeometry>();
	auto cubeMesh = Mesh(basicMaterial, cubeGeometry);

	Entity earth(std::make_shared<Mesh>(cubeMesh));
	entities.push_back(std::make_shared<Entity>(earth));

	// Satellite
	auto satMesh = Mesh(basicMaterial, cubeGeometry);
	SatelliteBasicView sat(std::make_shared<Mesh>(satMesh));
	entities.push_back(std::make_shared<SatelliteBasicView>(sat));
}
