/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "IceBreaker.h"

/* Constructor */
IceBreaker::IceBreaker(void) {
	renderer = new GLRenderer();
	renderer->Initialize();
	input = new Input();

	fManager = ForceManager::GetInstance();
	fwManager = new FireworkManager();


	leftAnchor = new Particle(Vector4(-0.9f, 0.0f, 0.0f), Vector4(), Vector4(), 1);
	rightAnchor = new Particle(Vector4(0.9f, 0.0f, 0.0f), Vector4(), Vector4(), 1);
	bMaker = new BridgeMaker(25, leftAnchor->position, rightAnchor->position);

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
		renderer->DrawFireworks(fwManager);

		renderer->Draw(*leftAnchor, RenderMode::FILLED);
		renderer->Draw(*rightAnchor, RenderMode::FILLED);

		bMaker->Update(renderer->deltaTime);
		renderer->DrawBridge(bMaker->bridgePieces);

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer->window) == 0);

	// End all GLFW functionality
	glfwTerminate();
}