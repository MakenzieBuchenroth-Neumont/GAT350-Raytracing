#include "Renderer.h"
#include "Ray.h"
#include "Random.h"
#include "Canvas.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Material.h"
#include <iostream>
#include <memory>

int main(int, char**) {
	std::cout << "Hello World";

	seedRandom(time(0));

	Renderer renderer;
	renderer.initialize();
	renderer.createWindow("Raytracing", 400, 300);

	Canvas canvas(400, 300, renderer);

	float aspectRatio = canvas.getSize().x / (float)canvas.getSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene(20); // sky color could be set with the top and bottom color
	scene.SetCamera(camera);

	// create material
	auto lambertian = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });
	auto metal = std::make_shared<Metal>(color3_t{ 1, 1, 1 }, 0.0f);

	// create objects -> add to scene
	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<Material> material = (rand() % 2 == 0) ? std::dynamic_pointer_cast<Material>(lambertian) : std::dynamic_pointer_cast<Material>(metal);
		auto sphere = std::make_unique<Sphere>(glm::vec3{ random(-3, 3), random(-3,3), random(-2, -10) }, 1, material);
		scene.AddObject(std::move(sphere));
	}
		// render scene
		canvas.clear({ 0, 0, 0, 1 });
		scene.render(canvas, 50);
		canvas.update();

	bool quit = false;
	while (!quit) {
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		renderer.presentCanvas(&canvas);
	}

	renderer.shutdown();

	return 0;
}