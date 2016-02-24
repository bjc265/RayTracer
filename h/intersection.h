#ifndef INTERSECTION_H
#define INTERSECTION_H


#include <armadillo>
#include "ray.h"



namespace rtrace
{
	namespace surface
	{
		class Surface;
	}

	class Intersection
	{
	private:
		Ray ray;
		surface::Surface* surf;
		double t;
		arma::vec3 location;
		

	public:
		Intersection();
		Ray const getRay();
		surface::Surface& getSurface();
		double const getT();
		arma::vec const getLocation();
		void setIntersection(Ray r, surface::Surface& s, double tn, arma::vec l);
	};
}

#endif