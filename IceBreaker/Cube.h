/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef CUBE
#define CUBE

#include "Particle.h"
#include "Matrix4.h"

/* Cube */
/*  ** It's a cube! */
class Cube : public Particle
{
public:
	public:
	/* Constructor */
	Cube(void);

	/* Constructor */
	/*  **** Vector4 pos: Position */
	/*  **** Vector4 vel: Velocity */
	/*  **** Vector4 accel: Acceleration */
	/*  **** float m: Mass */
	Cube(Vector4 pos, Vector4 vel, Vector4 accel, float m);

	/* Destructor */
	~Cube(void);
};
#endif

