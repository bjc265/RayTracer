#include "diffuseshader.h"
#include "surface.h"
#include "scene.h"

namespace rtrace
{
	namespace shader
	{
		DiffuseShader::DiffuseShader(Color c)
		{
			diffuseColor = c;
		}

		Shader* DiffuseShader::getAsHeapObject()
		{
			return new DiffuseShader(diffuseColor);
		}

		Color DiffuseShader::shade(Intersection intersect, std::vector<light::Light*> lights)
		{
			Color c(0,0,0);

			c += diffuseColor * light::Light::AMBIENT_COEFFICIENT;
			for(light::Light* light : lights)
			{
				arma::vec3 l = light->getLightVec(intersect.getLocation());
				Ray lightRay(intersect.getLocation(),arma::normalise(l));
				
				arma::vec3 v = intersect.getRay().getDirection();
				arma::vec3 n = intersect.getSurface().getNormalAt(intersect.getLocation());
				double ndotl = arma::norm_dot(n,l);
				ndotl = (ndotl <= 0 ? 0 : ndotl);
				c += diffuseColor * light->getIntensity() / arma::dot(l,l) * ndotl;
				
			}
			//std::cout << "\n" << c;
			return c;
		}
	}
}