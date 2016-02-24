#include "raytracer.h"
#include "dummycamera.h"
#include "dummylight.h"
#include "dummyshader.h"
#include "dummysurface.h"
#include "scene.h"
#include "color.h"


int main(int argc, const char* argv[])
{
	
	rtrace::Scene sc;	

	arma::vec3 v("0 5 10");
	rtrace::camera::DummyCamera dc;
	rtrace::light::DummyLight dl;
	rtrace::shader::DummyShader dsh;
	rtrace::Intersection inter;
	rtrace::surface::DummySurface ds(dsh);
	rtrace::Ray r;
	rtrace::Color bgc(127,0,0);

	sc.setBackgroundColor(bgc);
	sc.setCamera(&dc);
	sc.addSurface(ds);
	sc.addLight(dl);

	rtrace::RayTracer raytracer;
	raytracer.setScene(&sc);

	std::vector<rtrace::Color*>* img = raytracer.renderScene("  ",100,100);
	rtrace::Color* c = img->at(0);
	std::cout << "\n" << c->r << "\n";
	delete img;
}