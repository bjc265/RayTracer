#include "scene.h"
#include "camera.h"

namespace rtrace
{
	Scene::Scene()
	{
		camera = new camera::Camera();
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


	
	camera::Camera* Scene::getCamera() const
	{
		return camera;
	}
	

	void Scene::setCamera(camera::Camera& cam)
	{
		delete camera;
		camera = cam.getAsHeapObject();
		std::cout << "Set scene camera to " << camera->getPosition() << "\n";
	}

	std::vector<surface::Surface*> Scene::getSurfaces()
	{
		return surfaces;
	}

	void Scene::addSurface(surface::Surface& s)
	{
		surfaces.push_back(s.getAsHeapObject());
	}

	std::vector<light::Light*> Scene::getLights()
	{
		return lights;
	}

	void Scene::addLight(light::Light& l)
	{
		lights.push_back(&l);
	}

	Intersection Scene::getClosestIntersection(Ray camRay)
	{
		Intersection closestIntersection;
		for(size_t sn=0; sn<surfaces.size(); sn++)
		{
			Intersection inter = surfaces[sn]->intersect(camRay);
			if(inter.getT() > 0 && (closestIntersection.getT() < 0 || inter.getT() < closestIntersection.getT()))
			{
				closestIntersection = inter;
			}
		}
		//closestIntersection is now the closest intersection with a positive t value, or some intersection with a negative t value if no intersections occurred.
		return closestIntersection;

	}

	bool Scene::getAnyIntersection(Ray camRay)
	{
		Intersection closestIntersection;
		for(size_t sn=0; sn<surfaces.size(); sn++)
		{
			Intersection inter = surfaces[sn]->intersect(camRay);
			if(inter.getT() > 0 && (closestIntersection.getT() < 0 || inter.getT() < closestIntersection.getT()))
			{
				return true;
			}
		}
		return false;
	}
}