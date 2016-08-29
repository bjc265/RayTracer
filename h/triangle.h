#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "surface.h"
#include <armadillo>

namespace rtrace
{
	namespace surface
	{
		class Triangle : public Surface
		{
		private:
			arma::vec3 a;
			arma::vec3 b;
			arma::vec3 c;
			arma::vec3 n;

		public:
			Triangle(arma::vec3 p0, arma::vec3 p1, arma::vec3 p2);
			Triangle(arma::vec3 p0, arma::vec3 p1, arma::vec3 p2, shader::Shader& s);

			Intersection intersect(Ray r);
			arma::vec3 getNormalAt(arma::vec3 pos);

			Surface* getAsHeapObject() {return new Triangle(*this);}
		};
	}
}




#endif
