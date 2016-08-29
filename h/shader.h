#ifndef SHADER_H
#define SHADER_H

class Surface;

#include "intersection.h"
#include "color.h"
#include "light.h"


namespace rtrace
{
	namespace shader
	{
		class Shader
		{
		public:
			virtual Color shade(Intersection intersect, std::vector<light::Light*> lights) {
				std::cout << "D";
				Color c(0,0,0); return c;}
			virtual Shader* getAsHeapObject() {return new Shader();}
		};
	}
}

#endif