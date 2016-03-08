#include "raytracer.h"
#include "orthographiccamera.h"
#include "sphere.h"
#include "flatshader.h"
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
	Color sc(255,0,0);
	scene.setBackgroundColor(bgc);
	scene.setCamera(cam);

	


	arma::vec3 pos("0 0 0");
	shader::FlatShader fs(sc);
	surface::Sphere* sphere = new surface::Sphere(pos,1.0,fs);

	scene.addSurface(*sphere);

	std::cout << scene.getSurfaces()[0] << "\n";

	raytracer.setScene(scene);

	std::cout << raytracer.getScene().getSurfaces()[0] << "\n";

	std::vector<Color> img = raytracer.renderScene("",160,90);

	std::cout << "\n" << img[2] << "\n";

	raytracer.saveAsPPM("test.ppm",img,160,90);
}
