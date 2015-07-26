/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef GRAVITY_GENERATOR
#define GRAVITY_GENERATOR

#include "Vector4.h"
#include "ForceGenerator.h"

class GravityGenerator : public ForceGenerator
{
	Vector4 gravity;

public:
	/* Constructor */
	GravityGenerator(void);

	/* Destructor */
	~GravityGenerator(void);

	/* Update */
	/*  ** Updates force being applied on particle  */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

