#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "surface.h"
#include "light.h"


namespace rtrace
{
	class Scene
	{
	private:
		camera::Camera& camera;
		std::vector<surface::Surface*> surfaces;
		std::vector<light::Light*> lights;
	public:
		camera::Camera& getCamera();
		void setCamera(camera::Camera& cam);
		std::vector<surface::Surface*>& getSurfaces();
		void addSurface(surface::Surface& s);
		std::vector<light::Light*>& getLights();
		void addLight(light::Light& l);
	};
}

#endif