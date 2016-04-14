#include <png++/png.hpp>
#include "intersection.h"
#include "raytracer.h"
#include "surface.h"
#include "shader.h"
#include "light.h"
#include "sphere.h"
#include <vector>



namespace rtrace
{



	void RayTracer::setConfig(RayTracerConfig c)
	{
		config = c;
	}

	std::vector<Color> RayTracer::renderScene(std::string scenefile_path, int width, int height)
	{
		buildScene(scenefile_path);
		return renderCurrentScene(width, height);
	}

	void RayTracer::saveAsPPM(std::string filename, std::vector<Color> img, int width, int height)
	{
		std::ofstream ofs;

		
			ofs.open(filename, std::ios::binary);
			ofs << "P6\n" << width << " " << height << "\n255\n";
			for(int i=0; i<height; i++)
			{
				for(int j=0; j<width; j++)
				{
					Color c = img[width*i+j];
					ofs << (unsigned char)(c.r > 255 ? 255 : c.r) << (unsigned char)(c.g > 255 ? 255 : c.g) << (unsigned char)(c.b > 255 ? 255 : c.b);
				}
				
			}
			ofs.close(); 
		
	}


	void RayTracer::buildScene(std::string scenefile_path)
	{

	}

	std::vector<Color> RayTracer::renderCurrentScene(int width, int height)
	{
		//TODO refactor
		camera::Camera* cam = scene->getCamera();
		std::vector<light::Light*> lights = scene->getLights();
		std::vector<Color> img(width*height);
		Color bgc = scene->getBackgroundColor();
		

		
		for(int j=0; j<height; j++)
		{
			for (int i=0; i<width; i++)
			{
				Ray camRay = cam->getCameraRay(((double)i)/((double)width), ((double)j)/((double)height));
				Intersection closestIntersection = scene->getClosestIntersection(camRay);
				if(closestIntersection.getT()>0)
				{
					//shade 
					std::vector<light::Light*> relevantLights;
					for(light::Light* l : lights)
					{
						Ray r(closestIntersection.getLocation(),l->getLightVec(closestIntersection.getLocation()));
						if(!scene->getAnyIntersection(r))
						{
							relevantLights.push_back(l);
						}
					}
					img[j*width+i] = closestIntersection.getSurface().getShader().shade(closestIntersection, relevantLights);
				}
				else
				{
					img[j*width+i] = bgc;
				}
			}
		}

		return img;
	}

	

	Scene& RayTracer::getScene()
	{
		return *scene;
	}

	void RayTracer::setScene(Scene& s)
	{
		scene = &s;
	}
}