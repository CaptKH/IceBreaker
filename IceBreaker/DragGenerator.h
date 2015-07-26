/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef DRAG_GENERATOR
#define DRAG_GENERATOR

#include "ForceGenerator.h"

class DragGenerator : public ForceGenerator
{
	float k1;
	float k2;

public:
	/* Constructor */
	DragGenerator(float _k1, float _k2);

	/* Destructor */
	~DragGenerator(void);

	/* Update */
	/*  ** Imposes drag effects on particle */
	virtual void Update(Particle* p, float deltaTime);
};
#endif

