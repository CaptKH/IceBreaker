/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Camera.h"

/* Constructor */
Camera::Camera(Vector4& pos) {
	position = pos;
	up = Vector4();
	right = Vector4();

	hAngle = 3.14159f;
	vAngle = 0.0f;
	initialFoV = 45.0f;

	speed = 2.0f;
	mouseSpeed = 0.001f;
}

/* Destructor */
Camera::~Camera(void) {
}

/* Update */
Matrix4& Camera::Update(int windowWidth, int windowHeight, double mouseX, double mouseY, double deltaTime) {
	hAngle += mouseSpeed * deltaTime * float(windowWidth/2 - mouseX);
	vAngle += mouseSpeed * deltaTime * float(windowHeight/2 - mouseY);

	direction = Vector4(cosf(vAngle) * sinf(hAngle),
						sinf(vAngle),
						cosf(vAngle) * cosf(hAngle), 0);

	right = Vector4(sinf(hAngle - 3.14159/2.0f),
					0,
					cosf(hAngle - 3.14159/2.0f), 0);

	up = right.CrossProduct(direction);
	up.z = 0.0f;

	return Mat4::LookAt(position, position + direction, up);
}
