#include "Scene.h"

Scene::Scene() {
	camera = std::make_shared<Camera>();
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
	//entities.push_back(std::make_shared<Entity>(bg));


	// Satellite
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, "BasicVS.glsl");
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, "BasicFS.glsl");

	auto basicProgram = std::make_shared<Program>();
	basicProgram->AttachShader(vertexShader)
		.AttachShader(fragmentShader)
		.LinkProgram()
		.Bind();

	auto material = std::make_shared<Material>(basicProgram);
	std::shared_ptr<Geometry> geometry = std::make_shared<CubeGeometry>();
	auto mesh = Mesh(material, geometry);
	Satellite sat(std::make_shared<Mesh>(mesh));
	entities.push_back(std::make_shared<Satellite>(sat));

	//GlobeCube
	std::shared_ptr<Geometry> cubeGeometry = std::make_shared<CubeGeometry>();
	auto cubeMesh = Mesh(material, cubeGeometry);
	Entity cube(std::make_shared<Mesh>(cubeMesh));
	//entities.push_back(std::make_shared<Entity>(cube));
}

void Scene::update(float dt)
{
	camera->animate(dt);

	for (auto const& e : entities) {
		e->update(dt);
	}
}

void Scene::draw()
{
	for (auto const& e : entities) {
		e->draw(camera);
	}
}

void Scene::onKeyboard(unsigned char key)
{
	camera->processKey(key, KEYDOWN);
}

void Scene::onKeyboardUp(unsigned char key)
{
	camera->processKey(key, KEYUP);
}

void Scene::onMouse(int button, int state, int pX, int pY)
{
	if (state == GLUT_DOWN)
		camera->processMouseButton(KEYDOWN, pX, pY);
	if (state == GLUT_UP)
		camera->processMouseButton(KEYUP, pX, pY);
}

void Scene::onMouseMotion(int pX, int pY)
{
	camera->processMouseMove(pX, pY);
}
