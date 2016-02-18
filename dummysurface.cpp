#include "dummysurface.h"
#include "dummyshader.h"

namespace rtrace
{
	namespace surface
	{
		DummySurface::DummySurface()
		{
			shader::DummyShader ds;
			shadr = &ds;
		}
		DummySurface::DummySurface(shader::Shader& sh)
		{
			shadr = &sh;
		}

		bool DummySurface::intersect(Ray& ray, Intersection& intersect)
		{
			return false;
		}
	}
}