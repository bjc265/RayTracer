#ifndef CAMERA_H
#define CAMERA_H

#include <armadillo>
#include "ray.h"

namespace rtrace
{
	namespace camera
	{
		class Camera
		{
		public:
			Ray getCameraAsRay();
			arma::vec getPosition() const;
			void setPosition(arma::vec v);
			arma::vec getDirection() const;
			void setDirection(arma::vec v);
			virtual Ray getCameraRay(double u, double v) = 0;
		protected:
			Ray camRay;

		
		};
	}
}

#endif