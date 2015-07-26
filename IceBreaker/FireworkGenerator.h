/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FIREWORK_GENERATOR
#define FIREWORK_GENERATOR

#include <vector>
#include <random>
#include <time.h>
#include "Firework.h"
#include "ForceManager.h"


class FireworkGenerator
{
public:
	vector<Firework*> fireworks;
	vector<Firework*> nextFrame;

	/* Constructor */
	/*  **** float xPos: Initial x position */
	/*  **** float yPos: Initial y position */
	FireworkGenerator(float xPos, float yPos);

	/* Destructor */
	~FireworkGenerator(void);

	/* Update */
	/*  ** Update fireworks currently active, returns true if there are still active fireworks to draw */
	/*  **** float deltaTime: Time since last frame */
	bool Update(float deltaTime);
	
	/* BlowUp */
	/*  ** If a firework has reached its fusetime, blow it up! */
	/*  **** Firework* fw: Firework to blow up */
	void BlowUp(Firework* fw);
};
#endif
