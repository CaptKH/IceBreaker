/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "IceBreaker.h"

/* Constructor */
IceBreaker::IceBreaker(void) {
	renderer = new GLRenderer();
	renderer->Initialize();

	input = new Input();
	cube1 = new Cube();

	fwGenerators = vector<FireworkGenerator*>();

	srand(time(NULL));
}

/* Destructor */
IceBreaker::~IceBreaker(void) {
	if(renderer != nullptr)
		delete renderer;
		renderer = nullptr;
}

/* Initialize */
void IceBreaker::Initialize() {
}

/* Run */
void IceBreaker::Run() {
	do {
		// Get user input
		input->GetInput(renderer->window, renderer->camera, renderer->deltaTime, fwGenerators);

		// Refresh screen
		renderer->Update();

		for(FireworkGenerator* fwg : fwGenerators) {
			fwg->Update(renderer->deltaTime);
			
			for(Firework* fw : fwg->fireworks) {
				renderer->Draw(*fw, RenderMode::FILLED);
			}
		}

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(renderer->window) == 0);
}