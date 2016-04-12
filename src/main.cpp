#include "raytracer.h"
#include "orthographiccamera.h"
#include "sphere.h"
#include "diffuseshader.h"
#include "pointlight.h"
#include <iostream>

using namespace rtrace;

int main(int argc, const char* argv[])
{
	RayTracer raytracer;
	Scene scene;
	


	arma::vec3 camPos("0 -5 0");
	arma::vec3 camDir("0 2 0");
	arma::vec3 camU("0 0 1");
	camera::OrthographicCamera cam(camPos, camDir, camU,5,5);


	Color bgc(6,9,69);
	Color sc(100,0,0);
	scene.setBackgroundColor(bgc);
	scene.setCamera(cam);


	arma::vec3 lightPos("-1 -20 -3");
	Color lightColor(42,42,42);
	light::PointLight pl(lightPos,lightColor,50.00);	


	arma::vec3 pos("0 0 0");
	shader::DiffuseShader fs(sc);
	surface::Sphere* sphere = new surface::Sphere(pos,2.0,fs);

	scene.addSurface(*sphere);
	scene.addLight(pl);

	raytracer.setScene(scene);

	std::vector<Color> img = raytracer.renderScene("",1280,720);


	raytracer.saveAsPPM("test.ppm",img,1280,720);
}
