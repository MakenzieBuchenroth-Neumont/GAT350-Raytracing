#pragma once

template<typename T>
inline T lerp(const T* a, const T* b, float t);

template<typename T>
T lerp(const T* a, const T* b, float t) {
	lerp(a, b, t) = a + t * (b - a);
}