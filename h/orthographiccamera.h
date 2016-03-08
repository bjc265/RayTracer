#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include "camera.h"
#include "ray.h"

namespace rtrace
{
	namespace camera
	{
		class OrthographicCamera : public Camera
		{
		private:
			arma::vec3 side;
			double width;
			double height;

		public:
			OrthographicCamera(arma::vec3 p,arma::vec3 d, arma::vec3 u, double w, double h);

			double getWidth() const {return width;}
			void setWidth(double w) {width = w;}
			double getHeight() const {return height;}
			void setHeight(double h) {height = h;}

			void setDirection(arma::vec3 v);
			void setUpDirection(arma::vec3 v);

			Ray getCameraRay(double u, double v);

			Camera* getAsHeapObject();
		};
	}
}

#endif