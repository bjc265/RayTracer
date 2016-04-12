#ifndef DIFFUSESHADER_H
#define DIFFUSESHADER_H

#include "shader.h"

namespace rtrace
{
	namespace shader
	{
		class DiffuseShader : public Shader
		{
		private:
			Color diffuseColor;

		public: 
			DiffuseShader(Color c);
			Color shade(Intersection intersect, std::vector<light::Light*> lights);
			Shader* getAsHeapObject();
		};
	}
}

#endif