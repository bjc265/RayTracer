 	#pragma once

#include <armadillo>
#include "ray.h"

namespace rtrace
{
	namespace camera
	{
		class Camera
		{
		protected:
			Ray camRay;

		public:
			Camera();
			Ray getCameraAsRay();
			arma::vec getPosition();
			void setPosition(arma::vec v);
			arma::vec getDirection();
			void setDirection(arma::vec v);
			virtual Ray getCameraRay(double u, double v) = 0;
		};
	}
}