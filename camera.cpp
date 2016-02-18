#include "camera.h"

namespace rtrace
{
	namespace camera
	{
		Ray Camera::getCameraAsRay() const
		{
			return camRay;
		}
		arma::vec Camera::getPosition() const
		{
			return camRay.getPosition();
		}
		void Camera::setPosition(arma::vec v)
		{
			camRay.setPosition(v);
		}
		arma::vec Camera::getDirection() const
		{
			return camRay.getDirection();
		}
		void Camera::setDirection(arma::vec v)
		{
			camRay.setDirection(v);
		}
	}
}