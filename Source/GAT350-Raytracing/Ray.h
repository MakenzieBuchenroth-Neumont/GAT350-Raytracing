#pragma once
#include <glm/glm.hpp>

struct ray_t
{
	ray_t() = default;
	ray_t(const glm::vec3& origin, const glm::vec3& direction) :
		m_origin{origin},
		m_direction{direction}
	{}

	glm::vec3 at(float t) const { return m_origin + ((normalize(m_direction)) * t); }
	glm::vec3 GetPoint(float distance) const { return m_origin + (distance * normalize(m_direction)); }
	glm::vec3 operator * (float distance) const { return m_origin + (distance * normalize(m_direction)); }

	glm::vec3 m_origin{ 0 };
	glm::vec3 m_direction{ 0 };
};