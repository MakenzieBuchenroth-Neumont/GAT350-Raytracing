#include "Renderer.h"
#include "Ray.h"
#include "Random.h"
#include "Canvas.h"
#include <iostream>

int main(int, char**) {
	std::cout << "Hello World";

	Renderer renderer;
	renderer.initialize();
	renderer.createWindow("Raytracing", 400, 300);

	Canvas canvas(400, 300, renderer);

	canvas.clear({ 0,0,0,1 });
	for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, 400), random(0, 300) }, { random(0,255), random(0,255), random(0,255), 1 });
	canvas.update();
	renderer.presentCanvas(canvas);

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