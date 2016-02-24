#include "ray.h"

namespace rtrace
{
	Ray::Ray()
	{
		arma::vec3 p;
		arma::vec3 d;
		position = p;
		direction = d;
	}

	Ray::Ray(arma::vec3 p, arma::vec3 d)
	{
		position = p;
		direction = d;
	}

	arma::vec3 Ray::getPosition() const
	{
		return position;
	}

	void Ray::setPosition(arma::vec3 v)
	{
		position = v;
	}

	arma::vec3 Ray::getDirection() const
	{
		return direction;
	}

	void Ray::setDirection(arma::vec3 v)
	{
		direction = v;
	}

	Ray& Ray::negate()
	{
		direction = direction * -1;
		return *this;
	}

	Ray& Ray::normalize()

	{
		direction = arma::normalise(direction);
		return  *this;
	}


	
}