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
		protected:
			arma::vec3 position;
			arma::vec3 direction;
			arma::vec3 up;
		
		public:
			Ray getCameraAsRay()
			{
				Ray r(position,direction);
				return r;
			}
			arma::vec3 getPosition() const {return position;}
			virtual void setPosition(arma::vec3 v) {position = v;}
			arma::vec3 getDirection() const {return direction;}
			virtual void setDirection(arma::vec3 v) {direction = v;}
			arma::vec3 getUpDirection() const {return up;}
			virtual void setUpDirection(arma::vec3 v) {up = v;}
			
			virtual Ray getCameraRay(double u, double v)
			{
				arma::vec3 q("0 0 0");
				Ray r(q,q);
				return r;
			}
			virtual Camera* getAsHeapObject() {return new Camera(*this);}
		
		};
	}
}

#endif