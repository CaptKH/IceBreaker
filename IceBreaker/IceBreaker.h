/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef ICEBREAKER
#define ICEBREAKER

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include "GLRenderer.h"
#include "GameObject.h"
#include "Camera.h"
#include "Input.h"
#include "Cube.h"

using namespace std;

class IceBreaker
{
	Camera* camera;
	GLRenderer* renderer;
	Input* input;
	Cube* cube1;
	Cube* cube2;

	vector<GameObject*> gameObjects;

public:
	/* Constructor */
	IceBreaker(void);
	
	/* Destructor */
	~IceBreaker(void);

	/* Initialize */
	/*  Sets up IceBreaker engine */
	void Initialize();

	/* Run */
	/*  Updates gameobjects currently active in engine and draws them to screen */
	void Run();
};
#endif