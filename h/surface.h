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
			virtual arma::vec3 getNormalAt(arma::vec3 pos) {arma::vec3 v("0 0 0"); return v;}
			virtual Intersection intersect(Ray ray) {Intersection i; return i;}
			virtual Surface* getAsHeapObject() {return new Surface();}
		};
	}
}

#endif