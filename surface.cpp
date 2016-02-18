#include "surface.h"
#include "dummyshader.h"

namespace rtrace
{
	namespace surface
	{
		shader::Shader& Surface::getShader()
		{
			return *shadr;
		}

		void Surface::setShader(shader::Shader& s)
		{
			shadr = &s;
		}
	}
}