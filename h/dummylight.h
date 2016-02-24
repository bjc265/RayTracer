#ifndef DUMMYLIGHT_H
#define DUMMYLIGHT_H

#include "light.h"

namespace rtrace
{
	namespace light
	{
		class DummyLight : public Light
		{
		public:
			Ray getLightRay(arma::vec3 pos);
		};
	}
}

#endif