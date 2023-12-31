#include "Camera.h"
#include "Ray.h"
#include "Canvas.h"

void Camera::lookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3 up) {
	m_eye = eye;

	// set the camera axis vectors (forward, right, up)
	// forward vector (eye <- target)
	m_forward = glm::normalize(eye - target);
	// use cross product to create vectors
	// forward x up = right (vector perpindicular)
	m_right = glm::normalize(cross(up, m_forward));
	// right x forward = up (vector perpendicular)
	m_up = cross(m_forward, m_right);

	calculateViewPlane();
}

ray_t Camera::getRay(const glm::vec2& point) const {
	ray_t ray;
	// the ray origin is the camera eye
	ray.m_origin = m_eye;
	// calculate durectuib from point
	ray.m_direction = (m_lowerLeft + (m_horizontal * point.x) + (m_vertical * point.y)) - m_eye;

	return ray;
}

void Camera::calculateViewPlane() {
	// convert fov angle (degrees) to radians
	float theta = glm::radians(m_fov);

	// calculate the width / height of the view plane
	float halfHeight = tan(theta * 0.5f);
	float height = halfHeight * 2;
	float width = height * m_aspectRatio;

	// calculate horizontal vector (right vector * width)
	m_horizontal = m_right * width;
	// calculate vertical vector (up vector * height)
	m_vertical = m_up * height;
	// calculate lower left location (origin)
	m_lowerLeft = m_eye - (m_horizontal * 0.5f) - (m_vertical * 0.5f) - m_forward;
}
