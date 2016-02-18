#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "raytracerconfig.h"
#include "scene.h"
#include "color.h"

namespace rtrace
{
	class RayTracer
	{
	public:
		RayTracerConfig getConfig();
		void setConfig(RayTracerConfig c);
		Color* renderScene(std::string scenefile_path, int width, int height);


	public:			//for debugging purposes (remove eventually)
		Scene& getScene();
		void setScene(Scene s);

	private:
		RayTracerConfig config;
		Scene* scene;
		void buildScene(std::string scenefile_path);
		Color* renderCurrentScene(int width, int height);
	};
}

#endif