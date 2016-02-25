#include "dummycamera.h"
#include "ray.h"
#include <armadillo>

namespace rtrace
{
	namespace camera
	{
		DummyCamera::DummyCamera()
		{
			arma::vec3 v("0 0 0");
			position = v;
			direction = v;
			up = v;
		}

		Ray DummyCamera::getCameraRay(double u, double v)
		{
			Ray r(position,direction);
			return r;
		}
	}
}