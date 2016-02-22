#include "scene.h"
#include "dummycamera.h"

namespace rtrace
{
	Scene::Scene()
	{
		camera::DummyCamera dc;
		this->camera = &dc;
		std::vector<surface::Surface*> srs;
		surfaces = srs;
		std::vector<light::Light*> lts;
		lights = lts;
		Color bgc;
		backgroundColor = bgc;
	}

	Color Scene::getBackgroundColor() const
	{
		return backgroundColor;
	}
	
	void Scene::setBackgroundColor(Color c)
	{
		backgroundColor = c;
	}


	#pragma warning(push)
	#pragma warning(disable: 4101)
	camera::Camera& Scene::getCamera()
	{
		return *camera;
	}
	#pragma warning(pop)

	void Scene::setCamera(camera::Camera* cam)
	{
		camera = cam;
	}

	std::vector<surface::Surface*>& Scene::getSurfaces()
	{
		return surfaces;
	}

	void Scene::addSurface(surface::Surface& s)
	{
		surfaces.push_back(&s);
	}

	std::vector<light::Light*>& Scene::getLights()
	{
		return lights;
	}

	void Scene::addLight(light::Light& l)
	{
		lights.push_back(&l);
	}
}