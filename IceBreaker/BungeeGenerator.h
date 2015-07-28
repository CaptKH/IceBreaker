/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef BUNGEE_GENERATOR
#define BUNGEE_GENERATOR

#include "ForceGenerator.h"

class BungeeGenerator : public ForceGenerator
{
	Particle* other;
	float springConstant;
	float restLength;

public:
	/* Constructor */
	BungeeGenerator(Particle* p, float sC, float rL);
	
	/* Destructor */
	~BungeeGenerator(void);

	/* Update */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

