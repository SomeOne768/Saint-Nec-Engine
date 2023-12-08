#pragma once
#include <graphics/GraphicComponent.hpp>

class GrassComponent : public sne::graphics::GraphicComponent
{
public:
	GrassComponent(const int& width, const int& depth, const int nbInstances, const char* vertexShaderPath, const char* fragmentShaderPath);
	void draw() const override;

private:
	unsigned int instanceVBO;
	int nbInstances;


};
