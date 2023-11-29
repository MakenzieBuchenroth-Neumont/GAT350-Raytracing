#include "Renderer.h"
#include "Canvas.h"

#include <iostream>

bool Renderer::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Renderer::shutdown() {
    if (window) {
        SDL_DestroyWindow(window);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }

    SDL_Quit();
}

bool Renderer::createWindow(const std::string& title, int width, int height) {
    window = SDL_CreateWindow(title.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;

}

void Renderer::presentCanvas(const Canvas& canvas) {
    // copy canvas texture to renderer
    SDL_RenderCopy(renderer, canvas.m_texture, NULL, NULL);
    // present renderer to screen
    SDL_RenderPresent(renderer);
}
