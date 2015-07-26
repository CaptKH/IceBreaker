/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef INPUT
#define INPUT

#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>
#include "Particle.h"
#include "Camera.h"
#include "ForceManager.h"
#include "FireworkManager.h"

class Input
{
public:

	double mouseX;
	double mouseY;
	int windowW;
	int windowH;

	bool canClick;

	/* Constructor */
	/*	** Camera* cam: character-controlled camera used in scene */
	Input();

	/* Destructor */
	~Input(void);

	/* GetInput */
	/*  ** Handles processing of user input */
	/*  **** GLFWwindow* window: Window to get input from */
	/*  **** Camera* cam: Camera to move */
	/*  **** double deltaTime: Time since last frame */
	void GetInput(GLFWwindow* window, Camera* cam, double deltaTime, vector<FireworkGenerator*>& particles, ForceManager* fManager);
};
#endif

