#include "sphere.h"

namespace rtrace
{
	namespace surface
	{
		Sphere::Sphere(double r)
		{
			arma::vec3 c("0 0 0");
			center = c;
			radius = r;
			shadr = nullptr;
		}

		Sphere::Sphere(arma::vec3 c, double r)
		{
			center = c;
			radius = r;
			shadr = nullptr;
		}

		Sphere::Sphere(arma::vec3 c, double r, shader::Shader& s)
		{
			center = c;
			radius = r;
			shadr = &s;
		}

		Intersection Sphere::intersect(Ray ray)
		{
			arma::vec3 o = ray.getPosition();
			arma::vec3 l = arma::normalise(ray.getDirection());

			double bq = arma::dot(l,o-center);
			double cq = arma::dot(o-center,o-center)-radius*radius;

			double t1 = -bq + sqrt(bq*bq - cq);
			double t2 = -bq - sqrt(bq*bq - cq);
			if(t1<t2 && t1>=0)
			{
				arma::vec3 loc = o + l*t1;
				Intersection i(ray, this, t1, loc);
				return i;
			}
			else
			{
				arma::vec3 loc = 0 + l*t2;
				Intersection i(ray, this, t2, loc);
				return i;
			}
		}
	}
}