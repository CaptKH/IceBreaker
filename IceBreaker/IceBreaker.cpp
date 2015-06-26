/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "IceBreaker.h"

/* Constructor */
IceBreaker::IceBreaker(void) {
	camera = new Camera(Mat4::Translate(0.0f, 0.0f, 0.0f));
	renderer = new GLRenderer();
	input = new Input();
	cube1 = new Cube(Mat4::Translate(0.5f, 0.5f, 0.0f));
	cube2 = new Cube(Mat4::Translate(-0.5f, 0.5f, 0.5f));
}

/* Destructor */
IceBreaker::~IceBreaker(void) {
	if(camera != nullptr)
		delete camera;
		camera = nullptr;
	if(renderer != nullptr)
		delete renderer;
		renderer = nullptr;
}

/* Initialize */
void IceBreaker::Initialize() {
	renderer->Initialize();
}

/* Run */
void IceBreaker::Run() {
	do {
		// Get user input
		input->GetInput(renderer->window, *camera);

		// Refresh screen
		renderer->DrawRefresh();
		

		Matrix4 view = camera->position * camera->rotation * Mat4::Scale(Vector4(0.5, 0.5, 0.5, 0.5));

		renderer->DrawCube(cube1->position, view, RenderMode::FILLED);
		renderer->DrawCube(cube2->position, view, RenderMode::FILLED);

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(renderer->window) == 0);
}