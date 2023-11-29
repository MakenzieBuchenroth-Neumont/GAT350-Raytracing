#include "Canvas.h"
#include "Renderer.h"

Canvas::Canvas(int width, int height, const Renderer& renderer) {
	m_size = { width, height };
	m_texture = SDL_CreateTexture(renderer.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

	m_buffer.resize(width * height);
}

Canvas::~Canvas() {
	if (m_texture != nullptr) {
		SDL_DestroyTexture(m_texture);
	}
}

void Canvas::update() {
	// set texture with buffer rgba_t data

	SDL_UpdateTexture(m_texture, NULL, m_buffer.data(), m_size.x * sizeof(rgba_t));
}

void Canvas::clear(const color4_t& color) {
	rgba_t rgba = ColortoRGBA(color);
	std::fill(m_buffer.begin(), m_buffer.end(), rgba);
}

void Canvas::DrawPoint(const glm::ivec2& point, const color4_t& color) {
	if (point.x < 0 || point.y < 0 || point.x >= m_size.x || point.y >= m_size.x) return;
	m_buffer[point.x + (point.y * m_size.x)] = ColortoRGBA(color);
}
