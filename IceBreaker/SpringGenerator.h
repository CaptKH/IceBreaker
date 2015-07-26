/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef SPRING_GENERATOR
#define SPRING_GENERATOR

#include "ForceGenerator.h"

class SpringGenerator : public ForceGenerator
{
	Particle* other;

	float springConstant;
	float restLength;
public:
	/* Constructor */
	SpringGenerator(Particle* p, float sC, float rL);

	/* Destructor */
	~SpringGenerator(void);

	/* Update */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

