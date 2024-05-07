#include "Scene.h"

Scene::Scene() {
}

void Scene::build()
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
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, "BasicVS.glsl");
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, "BasicFS.glsl");

	auto basicProgram = std::make_shared<Program>();
	basicProgram->AttachShader(vertexShader)
		.AttachShader(fragmentShader)
		.LinkProgram()
		.Bind();

	auto material = std::make_shared<Material>(basicProgram);
	std::shared_ptr<Geometry> geometry = std::make_shared<PointGeometry>();
	auto mesh = Mesh(material, geometry);
	Satellite sat(std::make_shared<Mesh>(mesh));
	entities.push_back(std::make_shared<Satellite>(sat));
}

void Scene::update(float dt)
{
	for (auto const& e : entities) {
		e->update(dt);
	}
}

void Scene::draw()
{
	for (auto const& e : entities) {
		e->draw();
	}
}

void Scene::onKeyboard(unsigned char key)
{
	//Intentionally empty
}

void Scene::onKeyboardUp(unsigned char key)
{
	//Intentionally empty
}

void Scene::onMouse(int button, int state, int pX, int pY)
{
	//Intentionally empty
}

void Scene::onMouseMotion(int pX, int pY)
{
	//Intentionally empty
}
