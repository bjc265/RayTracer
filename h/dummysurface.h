#ifndef DUMMYSURFACE_H
#define DUMMYSURFACE_H

#include "surface.h"

namespace rtrace
{
	namespace surface
	{
		class DummySurface : public Surface
		{
		public:
			DummySurface();
			DummySurface(shader::Shader& sh);
			bool intersect(Ray& ray, Intersection& intersect);
		};
	}
}

#endif