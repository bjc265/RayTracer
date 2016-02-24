#ifndef RAY_H
#define RAY_H

#include <armadillo>

namespace rtrace
{
	class Ray
	{
	private:
		arma::vec3 position;
		arma::vec3 direction;

	public:
		Ray();
		Ray(arma::vec3 p, arma::vec3 d);
		arma::vec3 getPosition() const;
		void setPosition(arma::vec3 v);
		arma::vec3 getDirection() const;
		void setDirection(arma::vec3 v);
		Ray& negate();
		Ray& normalize();
	};
}

#endif