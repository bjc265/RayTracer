#include "orthographiccamera.h"
#include <armadillo>

namespace rtrace
{
	namespace camera
	{
		OrthographicCamera::OrthographicCamera(arma::vec3 p, arma::vec3 d, arma::vec3 u, double w, double h)
		{
			position = p;
			direction = arma::normalise(d);
			up = arma::normalise(u);
			side = arma::normalise(arma::cross(up,direction));
			width = w;
			height = h;
		}

		void OrthographicCamera::setDirection(arma::vec3 v)
		{
			direction = arma::normalise(v);
			side = arma::normalise(arma::cross(up,direction));
		}

		void OrthographicCamera::setUpDirection(arma::vec3 v)
		{
			up = arma::normalise(v);
			side = arma::normalise(arma::cross(up,direction));
		}

		Ray OrthographicCamera::getCameraRay(double u, double v)
		{
			arma::vec3 p = position + (u-0.5)*width*side + (v-0.5)*height*up;
			Ray r(p,direction);
			return r;
		}
	}
}