#ifndef SURFACE_H
#define SURFACE_H

#include "ray.h"
#include "shader.h"
#include "intersection.h"
#include "light.h"

namespace rtrace
{
	namespace surface
	{
		class Surface
		{
		protected:
			shader::Shader* shadr;
			
		public:
			shader::Shader& getShader();
			void setShader(shader::Shader& s);
			virtual bool intersect(Ray& ray, Intersection& intersect) = 0;
		};
	}
}

#endif