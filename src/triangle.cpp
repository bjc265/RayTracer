#define EPSILON 0.00001

#include "triangle.h"

namespace rtrace
{
	namespace surface
	{
		Triangle::Triangle(arma::vec3 p0, arma::vec3 p1, arma::vec3 p2)
		{
			a = p0;
			b = p1;
			c = p2;
			n = arma::normalise(arma::cross(p1-p0,p2-p0));
			shadr = nullptr;

		}

		Triangle::Triangle(arma::vec3 p0, arma::vec3 p1, arma::vec3 p2, shader::Shader& s)
		{
			a = p0;
			b = p1;
			c = p2;
			n = arma::normalise(arma::cross(p1-p0,p2-p0));
			shadr = &s;
		}

		arma::vec3 Triangle::getNormalAt(arma::vec3 pos)
		{
			return n;
		}

		Intersection Triangle::intersect(Ray ray)
		{
			arma::vec3 o = ray.getPosition();
			arma::vec3 d = arma::normalise(ray.getDirection());

			arma::vec3 e1 = b - a;
			arma::vec3 e2 = c - a;
			arma::vec3 p = arma::cross(d,e2);
			double det = arma::dot(p,e1);

			//if (near)parallel to triangle
			if(det < EPSILON)
			{
				Intersection i(ray, this, -1, o);
				return i;
			}

			double det_inv = 1.0/det;
			double u = arma::dot(-a,p) * det_inv;
			//if ray is outside of triangle
			if(u<0 || u>1) {
				Intersection i(ray, this, -1, o);
				return i;
			}

			arma::vec3 q = arma::cross(-a,e1);
			double v = arma::dot(d,q) * det_inv;
			if(v<0 || u+v > 1) {
				Intersection i(ray, this, -1, o);
				return i;
			}

			double t = arma::dot(e2,q);

			if(t > EPSILON) {
				arma::vec3 dist("0 0 0");
				dist[0] = o[0] + d[0]*t;
				dist[1] = o[1] + d[1]*t;
				dist[2] = o[2] + d[2]*t;
				Intersection i(ray, this, t, dist);
				//std::cout << "Triangle intersected at t=%d",t;
				return i;
			}

		}
	}
}