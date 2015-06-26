/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Input.h"

/* Constructor */
Input::Input() {
}

/* Destructor */
Input::~Input(void) {
}

/* GetInput */
void Input::GetInput(GLFWwindow* window, Camera& cam) {
	// Move Up
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cam.position = Mat4::Translate(0.0f, -0.005f, 0.0f) * cam.position;
	}
	// Move Down
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cam.position = Mat4::Translate(0.0f, 0.005f, 0.0f) * cam.position;
	}
	// Move Right
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cam.position = Mat4::Translate(0.005f, 0.0f, 0.0f) * cam.position;
	}
	// Move Left
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cam.position = Mat4::Translate(-0.005f, 0.0f, 0.0f) * cam.position;
	}
	// Rotate X-Axis
	if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		cam.rotation = Mat4::Rotate(Vector3(1.0f, 0.0f, 0.0f), 0.01) * cam.rotation;
	}
	// Rotate Y-Axis
	if(glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		cam.rotation = Mat4::Rotate(Vector3(0.0f, 1.0f, 0.0f), 0.01) * cam.rotation;
	}
	// Rotate Z-Axis
	if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		cam.rotation = Mat4::Rotate(Vector3(0.0f, 0.0f, 1.0f), 0.01) * cam.rotation;
	}
	// Scale Down
	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		cam.position = Mat4::Scale(Vector4(0.999 , 0.999 ,0.999, 1)) * cam.position;
	}
	// Scale Up
	if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		cam.position = Mat4::Scale(Vector4(1.001 , 1.001 ,1.001, 1)) * cam.position;
	}
}
