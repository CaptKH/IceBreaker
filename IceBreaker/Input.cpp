/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Input.h"

/* Constructor */
Input::Input() {
	mouseX = 0;
	mouseY = 0;
	windowW = 0;
	windowH = 0;

	canClick = true;
}

/* Destructor */
Input::~Input(void) {
}

/* GetInput */
void Input::GetInput(GLFWwindow* window, Camera* cam, double deltaTime, vector<FireworkGenerator*>& particles) {
	// Get mouse position
	glfwGetCursorPos(window, &mouseX, &mouseY);

	// Get window dimensions
	glfwGetWindowSize(window, &windowW, &windowH);

	// Move camera forward
	if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		cam->position -= Vector4(0, 0, deltaTime, 1);
	}
	// Move camera backward
	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		cam->position += Vector4(0, 0, deltaTime, 1);
	}
	// Move camera left
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cam->position += Vector4(deltaTime, 0, 0, 1);
	}
	// Move camera right
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cam->position -= Vector4(deltaTime, 0, 0, 1);
	}
	// Move camera up
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cam->position -= Vector4(0, deltaTime, 0, 1);
	}
	// Move camera down
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cam->position += Vector4(0, deltaTime, 0, 1);
	}

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && canClick == true) {
		float xPos = (mouseX - windowW/2)/(windowW/2);
		float yPos = (mouseY - windowH/2)/(windowH/2);

		FireworkGenerator* toAdd = new FireworkGenerator(xPos, -yPos);
		particles.push_back(toAdd);
		canClick = false;
	}

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) != GLFW_PRESS) {
		canClick = true;
	}
}
