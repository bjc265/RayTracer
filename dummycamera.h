#pragma once

#include "camera.h"

namespace rtrace
{
	namespace camera
	{
		class DummyCamera : Camera
		{
			Ray getCameraRay(double u, double v) = 0;
		};
	}
}