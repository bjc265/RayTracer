#include <png++/png.hpp>
#include "intersection.h"
#include "raytracer.h"
#include "surface.h"
#include "shader.h"
#include "light.h"
#include "sphere.h"



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
					ofs << (unsigned char)c.r << (unsigned char)c.g << (unsigned char)c.b;
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
		std::vector<surface::Surface*> surfaces = scene->getSurfaces();
		std::vector<Color> img(width*height);
		Color bgc = scene->getBackgroundColor();
		

		
		for(int j=0; j<height; j++)
		{
			for (int i=0; i<width; i++)
			{
				Intersection closestIntersection;
				Ray camRay = cam->getCameraRay(((double)i)/((double)width), ((double)j)/((double)height));
				//intersect all surfaces in the scene
				for(size_t sn=0; sn<surfaces.size(); sn++)
				{
					Intersection inter = surfaces[sn]->intersect(camRay);

					if(closestIntersection.getT()<0 || (inter.getT()>0 && closestIntersection.getT()<0))
					{
						closestIntersection = inter;
					}
				}
				//closestIntersection is now the closest intersection with a positive t value, or some intersection with a negative t value if no intersections occurred.

				if(closestIntersection.getT()>0)
				{
					Color c;
					//shade 
					for(size_t ln=0; ln<lights.size(); ln++)
					{
						c += closestIntersection.getSurface().getShader().shade(closestIntersection, *lights[ln]);
					}
					img[j*width+i] = c;
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