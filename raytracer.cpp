#include <png++/png.hpp>
#include "raytracer.h"

namespace rtrace
{


	void RayTracer::setConfig(RayTracerConfig c)
	{
		config = c;
	}

	Color* RayTracer::renderScene(std::string scenefile_path, int width, int height)
	{
		buildScene(scenefile_path);
		return renderCurrentScene(width, height);
	}

	void RayTracer::buildScene(std::string scenefile_path)
	{

	}
	Color* RayTracer::renderCurrentScene(int width, int height)
	{
		Color* img = new Color[width][height];
		return img;
	}

	Scene& RayTracer::getScene()
	{
		return scene;
	}
	void RayTracer::setScene(Scene s)
	{
		scene = &s;
	}
}