#include <png++/png.hpp>
#include "raytracer.h"
#include "surface.h"
#include "shader.h"
#include "light.h"

namespace rtrace
{


	void RayTracer::setConfig(RayTracerConfig c)
	{
		config = c;
	}

	std::vector<Color*>* RayTracer::renderScene(std::string scenefile_path, int width, int height)
	{
		buildScene(scenefile_path);
		return renderCurrentScene(width, height);
	}

	void RayTracer::buildScene(std::string scenefile_path)
	{

	}

	std::vector<Color*>* RayTracer::renderCurrentScene(int width, int height)
	{
		camera::Camera& cam = scene->getCamera();
		std::vector<light::Light*>& lights = scene->getLights();
		std::vector<surface::Surface*>& surfaces = scene->getSurfaces();
		std::vector<Color*>* img = new std::vector<Color*>();
		//std::cout << "far intersection about to be made \n";
		Intersection* aReallyFarIntersection = new Intersection();
		//std::cout << aReallyFarIntersection;
		Intersection* closestIntersection;

		
		for(int j=0;j<height;j++)
		{

			for(int i=0;i<width;i++)
			{

				Ray camRay = cam.getCameraRay(((double)i)/((double)width),((double)j)/((double)height));

				closestIntersection = aReallyFarIntersection;
				
				for(size_t sn = 0; sn < surfaces.size(); sn++)
				{

					surface::Surface* s = surfaces[sn];
					
					Intersection* inter = new Intersection();

					if(s->intersect(camRay,*inter))
					{
						if(inter->getT() < closestIntersection->getT())
						{
							if(closestIntersection!=aReallyFarIntersection)
							{
								delete closestIntersection;
							}
							closestIntersection = inter;
						}
						else
						{
							delete inter;
						}
					}
					else
					{

						delete inter;
					}
				}

				if(closestIntersection = aReallyFarIntersection)
				{
					Color* toAdd = new Color(scene->getBackgroundColor());
					img->push_back(toAdd);
				}
				else
				{
					Color* toAdd = new Color(0,0,0);
					for(size_t ln = 0; ln < lights.size(); ln++)
					{
						light::Light* l = lights[ln];
						*toAdd += closestIntersection->getSurface().getShader().shade(*closestIntersection,*l);
					}
					img->push_back(toAdd);
				}
			}
		}
		
		
		delete aReallyFarIntersection;
		return img;
	}

	Scene& RayTracer::getScene()
	{
		return *scene;
	}

	void RayTracer::setScene(Scene* s)
	{
		scene = s;
	}
}