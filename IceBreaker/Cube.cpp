/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */
#include "Cube.h"

/* Constructor */
Cube::Cube(Matrix4 pos) {
	position = pos;
	rotation = Matrix4(1.0f);
}

/* Destructor */
Cube::~Cube(void) {
}
