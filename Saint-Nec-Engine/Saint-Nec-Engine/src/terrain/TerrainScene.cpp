#include "TerrainScene.hpp"

TerrainScene::TerrainScene(): Scene::Scene()
{
}

void TerrainScene::load()
{
	gameObjects = std::vector<sne::GameObject*>();

	
	sne::GameObject* terrain = new sne::GameObject();
	terrain->setName("Terrain");
	addGameObject(terrain);	
	sne::graphics::Plane* plane = new sne::graphics::Plane(300, 300, 5, "resources/shaders/terrain/basic_terrain.vert", "resources/shaders/terrain/basic_terrain.frag");
	plane->addTexture("resources/textures/noise.jpg","heightmap");
	terrain->addComponent(plane);



	sne::GameObject* cubeMonoColor = new sne::GameObject();
	addGameObject(cubeMonoColor);
	cubeMonoColor->setName("Monocolor cube");
	cubeMonoColor->addComponent(new sne::graphics::Cube("resources/shaders/color.vert", "resources/shaders/color.frag", glm::vec3{ 0.5,0.2,0.6 }));
	cubeMonoColor->translate(glm::vec3{ 0.0f, 0.0f, 0.0f });

	
}

void TerrainScene::unload()
{
	for (sne::GameObject* g : gameObjects)
	{
		delete g;
	}
	gameObjects = std::vector<sne::GameObject*>();
}