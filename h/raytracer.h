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
		std::vector<Color> renderScene(std::string scenefile_path, int width, int height);
		void saveAsPPM(std::string filename, std::vector<Color> img, int width, int height);

	public:			//for use until building scenes from file is implemented (remove eventually)
		Scene& getScene();
		void setScene(Scene& s);

	private:
		RayTracerConfig config;
		Scene* scene;
		void buildScene(std::string scenefile_path);
		std::vector<Color> renderCurrentScene(int width, int height);
	};
}

#endif