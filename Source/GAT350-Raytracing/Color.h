#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/color_space.hpp>

using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = uint32_t;

inline color4_t RGBAtoColor(const rgba_t& rgba) {
	color4_t color;

	color.r = ((rgba >> 24) & 0xff) / 255.0f;
	color.g = ((rgba >> 16) & 0xff) / 255.0f;
	color.b = ((rgba >> 8) & 0xff) / 255.0f;
	color.a = ((rgba >> 0) & 0xff) / 255.0f;

	return color;
}
inline rgba_t ColortoRGBA(const color4_t& color) {
	rgba_t rgba = 0;

	rgba |= uint8_t(glm::clamp(color.r, 0.0f, 1.0f) * 255) << 24;
	rgba |= uint8_t(glm::clamp(color.g, 0.0f, 1.0f) * 255) << 16;
	rgba |= uint8_t(glm::clamp(color.b, 0.0f, 1.0f) * 255) << 8;
	rgba |= uint8_t(glm::clamp(color.a, 0.0f, 1.0f) * 255) << 0;

	return rgba;
}

// lerp(a,b,t) = a + t * (b-a)
// a - start val
// b - end val
// t - param that varies 0-1
// when t=0, result is a, when t=1, result is b;


// canvas

//void DrawPoint(const glm::ivec2& point, const color4_t& color);
// buffer[point.x + (point.y * m_size.x)] = ColortoRGBA(color);

//void Canvas::clear(const color4_t& color);
// rgba_t rgba = ColortoRGBA(color);
// std::fill(m_buffer.begin(), m_buffer.end(), rgba);

// pitch = width of buffer in bytes
// pitch = width * sizeof(rgba_t);
