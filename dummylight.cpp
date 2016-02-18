#include "dummylight.h"


namespace rtrace
{
	namespace light
	{

		Ray DummyLight::getLightRay(arma::vec3 pos)
		{
			arma::vec3 v("0 0 0");
			Ray r(v, pos);
			return r;
		}
	}
}