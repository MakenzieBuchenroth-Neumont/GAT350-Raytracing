#pragma once
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

inline void seedRandom(unsigned int seed) {
	srand(seed);
}
inline float random01() {
	return rand() / (float)RAND_MAX;
}

inline float random(float min, float max) {
	if (min > max) std::swap(min, max);

	float value = min + (max - min) * random01();
	return value;
}

inline glm::vec3 random(const glm::vec3& min, const glm::vec3& max) {
	float x = random(min.x, max.x);
	float y = random(min.y, max.y);
	float z = random(min.z, max.z);

	return { x,y,z };
}

inline glm::vec3 randomInUnitSphere()
{
	glm::vec3 v;
	// generate random vectors between -1 <-> +1, return vector if length is less than 1
	do
	{
	v = random({ -1,-1,-1 }, { 1,1,1 });
	} while (glm::length2(v) >= 1.0f);

		return v;
}