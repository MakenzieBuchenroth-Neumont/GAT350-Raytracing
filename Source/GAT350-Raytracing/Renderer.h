#pragma once
#include <string>
#include <SDL.h>

class Renderer {
public:
	Renderer() = default;

	bool initialize();
	void shutdown();
	bool createWindow(const std::string& title, int width, int height);

	void presentCanvas(const class Canvas& canvas);
	friend class Canvas;

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};
