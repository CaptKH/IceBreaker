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

	cube1->scale = Mat4::Scale(0.2f);

	particles = vector<Particle*>();

	particles.push_back(cube1);
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
		input->GetInput(renderer->window, renderer->camera, renderer->deltaTime, particles);

		// Refresh screen
		renderer->Update();

		Vector4 rand = Vec4::Random();


		for(Particle* p : particles) {
			p->Update(renderer->deltaTime);

			renderer->Draw(p, RenderMode::FILLED);
		}

		glfwSwapBuffers(renderer->window);
		glfwPollEvents();
	}
	while(glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(renderer->window) == 0);
}