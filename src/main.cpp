#include "raytracer.h"

using namespace rtrace;

int main(int argc, const char* argv[])
{
	RayTracer raytracer;
	Scene scene;

	Color bgc(6,9,69);
	scene.setBackgroundColor(bgc);

	raytracer.setScene(scene);
	std::vector<Color> img;
	img = raytracer.renderScene("",160,90);

	std::cout << "\n" << img[2] << "\n";
}
