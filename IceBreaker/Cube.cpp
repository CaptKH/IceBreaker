/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */
#include "Cube.h"

/* Default Constructor */
Cube::Cube(void) : Particle() {
	meshID = "Cube";

	scale = Mat4::Scale(0.3f);
}

/* Constructor */
Cube::Cube(Vector4 pos, Vector4 vel, Vector4 accel, float m) 
	: Particle(pos, vel, accel, m) {

	meshID = "Cube";
}

/* Destructor */
Cube::~Cube(void) {
}
