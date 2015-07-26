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
		// Refresh screen
		renderer->Update();

		// Get user input
		input->GetInput(renderer->window, renderer->camera, renderer->deltaTime, fwGenerators);

		vector<FireworkGenerator*> stillActive = vector<FireworkGenerator*>();

		for(FireworkGenerator* fwg : fwGenerators) {
			if(!fwg->Update(renderer->deltaTime)) {
				delete fwg;
			}
			else {
				stillActive.push_back(fwg);

				for(Firework* fw : fwg->fireworks) {
					renderer->Draw(*fw, RenderMode::FILLED);
				}
			}
		}

		fwGenerators = stillActive;

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer->window) == 0);

	// End all GLFW functionality
	glfwTerminate();
}