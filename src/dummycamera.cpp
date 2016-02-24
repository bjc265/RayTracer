#include "dummycamera.h"
#include "ray.h"

namespace rtrace
{
	namespace camera
	{
		DummyCamera::DummyCamera()
		{
			Ray r;
			camRay = r;
		}

		Ray DummyCamera::getCameraRay(double u, double v)
		{
			return camRay;
		}
	}
}