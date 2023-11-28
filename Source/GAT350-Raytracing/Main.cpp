#include "Renderer.h"
#include "Ray.h"
#include "Random.h"
#include <iostream>

int main(int, char**) {
	seedRandom((int)time(nullptr));

	for (int i = 0; i < 10; i++) {
		std::cout << random(1, 10) << std::endl;
	}

	std::cout << "Hello World";

	Renderer renderer;
	renderer.initialize();
	renderer.createWindow("Raytracing", 400, 300);

	bool quit = false;
	while (!quit) {
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}
	}

	renderer.shutdown();

	return 0;
}