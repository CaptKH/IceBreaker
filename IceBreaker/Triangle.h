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
	/*  **** Matrix4 t: translation matrix */
	/*  **** Matrix4 r: rotation matrix */
	/*  **** Matrix4 s: scale matrix */
	Triangle(Matrix4 t, Matrix4 r, Matrix4 s);

	/* Destructor */
	~Triangle(void);
};
#endif 

