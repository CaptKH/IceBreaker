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
void Input::GetInput(GLFWwindow* window, Camera* cam, double deltaTime) {
	// Move camera forward
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cam->position += cam->direction * deltaTime * cam->speed;
	}
	// Move camera backward
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cam->position -= cam->direction * deltaTime * cam->speed;
	}
	// Move camera left
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cam->position -= cam->right * deltaTime * cam->speed;
	}
	// Move camera right
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cam->position += cam->right * deltaTime * cam->speed;
	}
}
