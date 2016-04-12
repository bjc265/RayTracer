#include "pointlight.h"

namespace rtrace
{
	namespace light
	{
		PointLight::PointLight(arma::vec3 p, Color c, double i)
		{
			position = p;
			color = c;
			intensity = i;
		}
		Color PointLight::getColor()
		{
			return color;
		}
		double PointLight::getIntensity()
		{
			return intensity;
		}
		arma::vec3 PointLight::getLightVec(arma::vec3 pos)
		{
			return position - pos;
		}
	}
}