#include "raytracer.h"
#include "orthographiccamera.h"
#include "sphere.h"
#include "triangle.h"
#include "flatshader.h"
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
	camera::OrthographicCamera cam(camPos, camDir, camU,8.889,5);


	Color bgc(6,9,69);
	Color sc(200,0,0);
	scene.setBackgroundColor(bgc);
	scene.setCamera(cam);


	arma::vec3 lightPos("-4 -10 -3");
	Color lightColor(42,42,42);
	light::PointLight pl(lightPos,lightColor,300.00);

	arma::vec3 light1Pos("10 10 5");
	light::PointLight pl1(light1Pos,lightColor,300.00);	


	arma::vec3 pos("0 0 0");
	shader::DiffuseShader ds(sc);
	surface::Sphere sphere(pos,0.01,ds);

	arma::vec3 pos1("4 2 0");
	Color sc1(0,200,0);
	shader::DiffuseShader ds1(sc1);
	surface::Sphere sphere1(pos1,0.01,ds1);

	arma::vec3 tpos0("0 1 0");
	arma::vec3 tpos2("0 -1 -1");
	arma::vec3 tpos1("-1 -1 0");
	Color tc(0,200,200);
	shader::FlatShader ts(tc);
	surface::Triangle triangle(tpos0,tpos1,tpos2,ts);


	scene.addSurface(sphere1);
	scene.addSurface(sphere);
	scene.addSurface(triangle);
	
	scene.addLight(pl);
	//scene.addLight(pl1);

	raytracer.setScene(scene);

	std::vector<Color> img = raytracer.renderScene("",1280,720);


	raytracer.saveAsPPM("test.ppm",img,1280,720);


}
