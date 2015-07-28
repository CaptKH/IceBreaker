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
#include "MeshRegistry.h"
#include "Camera.h"
#include "Input.h"
#include "GameObject.h"
#include "Cube.h"
#include "ForceManager.h"
#include "FireworkManager.h"
#include "BridgeMaker.h"

using namespace std;

class IceBreaker
{
	GLRenderer* renderer;
	Input* input;

	ForceManager* fManager;
	FireworkManager* fwManager;

	BridgeMaker* bMaker;
	Particle* leftAnchor;
	Particle* rightAnchor;

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