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
		Intersection()
		{
			Ray r;
			arma::vec3 v("0 0 0");
			ray = r;
			surf = nullptr;
			t = -1;
			location = v;
		}
		Intersection(Ray r, surface::Surface* s, double tn, arma::vec3 l) {ray=r; surf=s; t=tn; location=l;}
		Ray getRay() const {return ray;}
		surface::Surface& getSurface() const {return *surf;}
		double getT() const {return t;}
		arma::vec getLocation() const {return location;}
	};
}

#endif