#ifndef FLATSHADER_H
#define FLATSHADER_H

#include "shader.h"

namespace rtrace
{
	namespace shader
	{
		class FlatShader : public Shader
		{
		private:
			Color color;

		public:
			FlatShader(Color c) {color = c;}
			Color shade(Intersection intersect, std::vector<light::Light*> lights) {
				
				return color;}
			Shader* getAsHeapObject() {return new FlatShader(color);}
		};
	}
}

#endif