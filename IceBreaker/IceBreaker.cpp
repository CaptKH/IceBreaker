/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "IceBreaker.h"

/* Constructor */
IceBreaker::IceBreaker(void) {
	renderer = new GLRenderer();
	input = new Input();
	cube1 = new Cube();
	cube2 = new Cube();

	cube2->translation = Mat4::Translate(3.0f, 2.0f, 0.0f);
	cube1->scale = Mat4::Scale(0.1f);
}

/* Destructor */
IceBreaker::~IceBreaker(void) {
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
		input->GetInput(renderer->window, renderer->camera, renderer->deltaTime);

		// Refresh screen
		renderer->Update();

		renderer->Draw(cube1, RenderMode::FILLED);
		renderer->Draw(cube2, RenderMode::FILLED);

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(renderer->window) == 0);
}