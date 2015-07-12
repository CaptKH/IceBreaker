/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef TRIANGLE
#define TRIANGLE

#include "Particle.h"

class Triangle : public Particle
{
public:
	/* Constructor */
	Triangle(void);

	/* Constructor */
	/*  **** Vector4 pos: Position */
	/*  **** Vector4 vel: Velocity */
	/*  **** Vector4 accel: Acceleration */
	/*  **** float m: Mass */
	Triangle(Vector4 pos, Vector4 vel, Vector4 accel, float m);

	/* Destructor */
	~Triangle(void);
};
#endif 

