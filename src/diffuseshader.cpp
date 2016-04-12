#include "diffuseshader.h"
#include "surface.h"

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
			for(light::Light* light : lights)
			{
				arma::vec3 l = light->getLightVec(intersect.getLocation());
				arma::vec3 v = intersect.getRay().getDirection();
				arma::vec3 n = intersect.getSurface().getNormalAt(intersect.getLocation());
				double ndotl = arma::norm_dot(n,l);
				ndotl = (ndotl <= 0 ? 0 : ndotl);
				//std::cout << "\n\n" << diffuseColor << "  " << light->getIntensity() << "  " << arma::dot(l,l) << "  " << intersect.getLocation() << "  " << l << "\n\n";
				c += diffuseColor * light->getIntensity() / sqrt(arma::dot(l,l)) * ndotl;
				arma::vec3 temp;
				//c.set(n[0]*256,n[1]*256,n[2]*256);
				//std::cout << "\n\n" << l;
			}
			//std::cout << "\n" << c;
			return c;
		}
	}
}