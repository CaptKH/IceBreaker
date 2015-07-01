/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Triangle.h"

/* Default Constructor */
Triangle::Triangle(void) : Particle() {
	meshID = "Triangle";
}

/* Constructor */
Triangle::Triangle(Matrix4 t, Matrix4 r, Matrix4 s) 
	: Particle(t, r, s) {

	meshID = "Triangle";
}

/* Destructor */
Triangle::~Triangle(void) {
}
