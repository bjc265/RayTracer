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
			Surface() {shadr = nullptr;}
			shader::Shader& getShader() {return *shadr;}
			void setShader(shader::Shader& s) {shadr = s.getAsHeapObject();}
			virtual Intersection intersect(Ray ray) {Intersection i; return i;}
			virtual Surface* getAsHeapObject() {return new Surface();}
		};
	}
}

#endif