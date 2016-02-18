#ifndef DUMMYSHADER_H
#define DUMMYSHADER_H

#include "shader.h"

namespace rtrace
{
	namespace shader
	{
		class DummyShader : public Shader
		{
		public:
			Color shade(Intersection& intersect, light::Light& light);
		};
	}
}

#endif