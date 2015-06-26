/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Camera.h"

/* Constructor */
Camera::Camera(Matrix4& pos) {
	position = pos;
	rotation = Matrix4(1.0f);
}

/* Destructor */
Camera::~Camera(void) {
}

/* LookAt */
Matrix4 Camera::LookAt(Matrix4 point) {
	Vector4 vecPoint = point * Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	//Matrix4 pos = rotation * position;

	Vector4 eye = position * Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	Vector4 up = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	return Mat4::LookAt(eye, vecPoint, up);
}
