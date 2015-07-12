/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Triangle.h"

/* Default Constructor */
Triangle::Triangle(void) : Particle() {
	meshID = "Triangle";
}

/* Constructor */
Triangle::Triangle(Vector4 pos, Vector4 vel, Vector4 accel, float m) 
	: Particle(pos, vel, accel, m) {

	meshID = "Triangle";
}

/* Destructor */
Triangle::~Triangle(void) {
}
