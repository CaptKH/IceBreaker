/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

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
	/*  **** Matrix4 t: translation matrix */
	/*  **** Matrix4 r: rotation matrix */
	/*  **** Matrix4 s: scale matrix */
	Cube(Matrix4 t, Matrix4 r, Matrix4 s);

	/* Destructor */
	~Cube(void);
};

