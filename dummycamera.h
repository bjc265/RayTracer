#ifndef DUMMYCAMERA_H
#define DUMMYCAMERA_H

#include "camera.h"

namespace rtrace
{
	namespace camera
	{
		class DummyCamera : public Camera
		{
		public:
			DummyCamera();
			Ray getCameraRay(double u, double v);
		};
	}
}

#endif