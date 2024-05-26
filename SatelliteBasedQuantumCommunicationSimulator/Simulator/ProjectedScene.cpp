#include "ProjectedScene.h"

ProjectedScene::ProjectedScene() : Scene() {}

void ProjectedScene::build()
{
	//Map
	GLuint texturedVS = CreateShader(GL_VERTEX_SHADER, "TexturedVS.glsl");
	GLuint texturedFS = CreateShader(GL_FRAGMENT_SHADER, "TexturedFS.glsl");

	auto texturedProgram = std::make_shared<Program>();
	texturedProgram->AttachShader(texturedVS).AttachShader(texturedFS).LinkProgram();
	auto texturedMaterial = std::make_shared<Material>(texturedProgram);

	auto fst = std::make_shared<FullScreenTexture>("../Resources/8081_earthmap2k.jpg");

	texturedMaterial->addTexture(fst, "textureColor");

	std::shared_ptr<Geometry> fullScreenQuad = std::make_shared<FullScreenQuadGeometry>();
	auto bgMesh = Mesh(texturedMaterial, fullScreenQuad);

	Entity bg(std::make_shared<Mesh>(bgMesh));
	entities.push_back(std::make_shared<Entity>(bg));


	// Satellite
	GLuint projectedVS = CreateShader(GL_VERTEX_SHADER, "ProjectedVS.glsl");
	GLuint basicFS = CreateShader(GL_FRAGMENT_SHADER, "BasicFS.glsl");

	auto projectedProgram = std::make_shared<Program>();
	projectedProgram->AttachShader(projectedVS)
		.AttachShader(basicFS)
		.LinkProgram()
		.Bind();

	auto material = std::make_shared<Material>(projectedProgram);
	std::shared_ptr<Geometry> geometry = std::make_shared<PointGeometry>();
	auto mesh = Mesh(material, geometry);
	SatelliteProjectedView sat(std::make_shared<Mesh>(mesh));
	entities.push_back(std::make_shared<SatelliteProjectedView>(sat));


}

void ProjectedScene::mouseMotionFunc(double x, double y)
{
	/// Intentionally empty
}

void ProjectedScene::mouseButtonFunc(int button, int action)
{
	// Intentionally empty
}

void ProjectedScene::keyEventFunc(int key, int action)
{
	// Intentionally empty
}