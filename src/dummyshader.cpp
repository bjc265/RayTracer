#include "dummyshader.h"

namespace rtrace
{
	namespace shader
	{

		Color DummyShader::shade(Intersection& intersect, light::Light& light)
		{
			Color c(0,0,0);
			return c;
		}
	}
}