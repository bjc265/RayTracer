#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light.h"
#include "color.h"

namespace rtrace
{
	namespace light
	{
		class PointLight : public Light
		{
		private:
			arma::vec3 position;
			Color color;
			double intensity;

		public:
			PointLight(arma::vec3 p, Color c, double i);
			Color getColor();
			double getIntensity();
			arma::vec3 getLightVec(arma::vec3 pos);
		};
	}
}

#endif