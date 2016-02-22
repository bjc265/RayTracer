#include "intersection.h"

namespace rtrace
{
	
	Intersection::Intersection()
	{
		Ray r;
		ray = r;
		surf = 0;
		t = std::numeric_limits<double>::max();
		arma::vec3 v("0 0 0");
		location = v;
	}

	Ray const Intersection::getRay(){
		return ray;
	}
	surface::Surface& Intersection::getSurface()
	{
		return *surf;
	}
	double const Intersection::getT()
	{
		return t;
	}
	arma::vec const Intersection::getLocation()
	{
		return location;
	}
	void Intersection::setIntersection(Ray r, surface::Surface& s, double tn, arma::vec l)
	{
		ray = r;
		surf = &s;
		t = tn;
		location = l;
	}
	
}