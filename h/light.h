#ifndef LIGHT_H
#define LIGHT_H

#include <armadillo>
#include "ray.h"

namespace rtrace
{
	namespace light
	{
		class Light
		{
			virtual Ray getLightRay(arma::vec3 pos)
			{
				arma::vec3 v("0 0 0");
				Ray r(v,v);
				return r;
			}
		};
	}
}

#endif