/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef INPUT
#define INPUT

#include <GLFW\glfw3.h>
#include <iostream>
#include "Camera.h"

class Input
{
public:
	/* Constructor */
	/*	Camera* cam: character-controlled camera used in scene */
	Input();

	/* Destructor */
	~Input(void);

	/* GetInput */
	/*  Handles processing of user input */
	/*  GLFWwindow* window: window to get input from */
	void GetInput(GLFWwindow* window, Camera& cam);
};
#endif

