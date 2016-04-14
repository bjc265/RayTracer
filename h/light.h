#ifndef LIGHT_H
#define LIGHT_H

#include <armadillo>
#include "ray.h"
#include "color.h"

namespace rtrace
{
	namespace light
	{
		class Light
		{

		public:
			static constexpr double AMBIENT_COEFFICIENT = .1;

		public:
			virtual Color getColor() {Color c(0,0,0); return c;}
			virtual double getIntensity() {return 0;}
			virtual arma::vec3 getLightVec(arma::vec3 pos)
			{
				arma::vec3 v("0 0 0");
				return v;
			}
		};
	}
}

#endif