/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */
#include "Cube.h"

/* Default Constructor */
Cube::Cube(void) : Particle() {
	meshID = "Cube";
}

/* Constructor */
Cube::Cube(Matrix4 t, Matrix4 r, Matrix4 s) 
	: Particle(t, r, s) {

	meshID = "Cube";
}

/* Destructor */
Cube::~Cube(void) {
}
