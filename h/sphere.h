#ifndef SPHERE_H
#define SPHERE_H

#include "surface.h"
#include <armadillo>

namespace rtrace
{
	namespace surface
	{
		class Sphere : public Surface
		{
		private:
			arma::vec3 center;
			double radius;

		public:
			Sphere(double r);
			Sphere(arma::vec3 c, double r);
			Sphere(arma::vec3 c, double r, shader::Shader& s);

			Intersection intersect(Ray ray);

			arma::vec3 getCenter() const {return center;}
			void setCenter(arma::vec3 v) {center = v;}
			double getRadius() const {return radius;}
			void setRadius(double r) {radius = r;}
			Surface* getAsHeapObject() {return new Sphere(*this);}
		};
	}
}

#endif