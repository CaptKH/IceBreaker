/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FORCE_GENERATOR
#define FORCE_GENERATOR

#include "Particle.h"

/* ForceGenerator */
/*  ** Interface for class that can impose forces on objects in game */
class ForceGenerator 
{
public:
	/* Update */
	/*  ** Imposes force on particle */
	/*  **** Particle* p: Particle to affect */
	/*  **** float deltaTime: Time to integrate over */
	virtual void Update(Particle* p, float deltaTime) = 0;
};
#endif

