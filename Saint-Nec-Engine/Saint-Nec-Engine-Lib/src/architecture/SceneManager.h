#pragma once
#include "../..pch.h"
#include <string>
#include "Scene.h"

namespace SaintNecLib
{
	class SceneManager
	{
		std::vector<Scene*> scenes;
	public:
		SceneManager() = default;
		~SceneManager() = default;
		void addScene(Scene& scene);
		void changeScene(std::string& name);

		void update();
		void draw() const;
	};
}