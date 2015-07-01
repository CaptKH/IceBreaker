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
		input->GetInput(renderer->window, *renderer->camera);

		// Refresh screen
		renderer->DrawRefresh();

		// MVP
		Matrix4 model = Matrix4(1.0f);
		Matrix4 projection = Mat4::Perspective(3.14159f/4.0f, 4.0f/3.0f, 0.1f, 100.0f);

		renderer->Draw(cube1, RenderMode::FILLED);
		renderer->Draw(cube2, RenderMode::FILLED);

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(renderer->window) == 0);
}