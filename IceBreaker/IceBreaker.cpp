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

	fManager = ForceManager::GetInstance();
	fwManager = new FireworkManager();

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
		// Refresh screen
		renderer->Update();

		// Get user input
		input->GetInput(renderer->window, renderer->camera, renderer->deltaTime, fwManager->generators, fManager);

		fManager->Update(renderer->deltaTime);

		// FIREWORKS
		fwManager->Update(renderer->deltaTime);
		DrawFireworks();

		fManager->CleanUp();

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer->window) == 0);

	// End all GLFW functionality
	glfwTerminate();
}

/* DrawFireworks */
void IceBreaker::DrawFireworks(void) {
	for(FireworkGenerator* fwg : fwManager->generators) {
		for(Firework* fw : fwg->fireworks) {
			renderer->Draw(*fw, RenderMode::FILLED);
		}
	}
}