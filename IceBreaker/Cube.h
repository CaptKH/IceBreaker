/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Matrix4.h"

class Cube
{
public:
	Matrix4 position;
	Matrix4 rotation;

	/* Constructor */
	/*  Matrix4 pos: initial position */
	Cube(Matrix4 pos);

	/* Destructor */
	~Cube(void);
};

