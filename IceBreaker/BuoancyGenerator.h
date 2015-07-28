/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef BUOANCY_GENERATOR
#define BUOANCY_GENERATOR

#include "ForceGenerator.h"

class BuoancyGenerator : public ForceGenerator
{
	float maxDepth;
	float volume;
	float waterHeight;
	float liquidDensity;

public:
	/* Constructor */
	/*  **** float mD: Max depth */
	/*  **** float v: Volume */
	/*  **** float wH: Water height */
	/*  **** float lD: Liquid density */
	BuoancyGenerator(float mD, float v, float wH, float lD = 1000.0f);

	/* Destructor */
	~BuoancyGenerator(void);

	/* Update */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

