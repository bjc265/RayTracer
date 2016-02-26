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
		Ray()
		{
			arma::vec3 p;
			arma::vec3 d;
			position = p;
			direction = d;
		}
		Ray(arma::vec3 p, arma::vec3 d)
		{
			position = p;
			direction = d;
		}

		arma::vec3 getPosition() const {return position;}
		void setPosition(arma::vec3 v) { position = v;}
		arma::vec3 getDirection() const {return direction;}
		void setDirection(arma::vec3 v) {direction = v;}
		
		Ray& negate()
		{
			direction = direction * -1;
			return *this;
		}
		Ray& normalize()
		{
			direction = arma::normalise(direction);
			return *this;
		}
	};
}

#endif