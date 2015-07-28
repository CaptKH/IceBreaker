
/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef ANCHORED_SPRING_GENERATOR
#define ANCHORED_SPRING_GENERATOR

#include "ForceGenerator.h"

class AnchoredSpringGenerator : public ForceGenerator
{
	float springConstant;
	float restLength;

public:
	Vector4 anchor;

	/* Constructor */
	AnchoredSpringGenerator(Vector4 a, float sC, float rL);

	/* Destructor  */
	~AnchoredSpringGenerator(void);

	/* Update */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

