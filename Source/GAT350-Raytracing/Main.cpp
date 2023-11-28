#include <iostream>

#include "Renderer.h"

int main(int, char**) {
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