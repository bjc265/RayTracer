#include "dummycamera.h"
#include "ray.h"

namespace rtrace
{
	namespace camera
	{

		Ray Camera::getCameraRay(double u, double v)
		{
			return this->getCameraAsRay();
		}
	}
}