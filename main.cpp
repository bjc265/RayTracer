#include "raytracer.h"
#include "dummycamera.h"
#include "dummylight.h"
#include "dummyshader.h"
#include "dummysurface.h"
#include "scene.h"


int main(int argc, const char* argv[])
{
	arma::vec3 v("0 5 10");
	rtrace::light::DummyLight dl;
	rtrace::shader::DummyShader dsh;
	rtrace::Intersection inter;
	rtrace::surface::DummySurface ds(dsh);
	rtrace::Ray r;

	std::cout << "\n";
	std::cout  << dl.getLightRay(v).getDirection() << "\n";
	std::cout << dsh.shade(inter,dl).r << "\n";
	std::cout << ds.intersect(r,inter) << "\n";





}