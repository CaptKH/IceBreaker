/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Particle.h"

/* Default Constructor */
Particle::Particle(void) {
	meshID = "Patricle";

	translation = Matrix4(1.0f);
	rotation = Matrix4(1.0f);
	scale = Matrix4(1.0f);
}

/* Constructor */
Particle::Particle(Matrix4 t, Matrix4 r, Matrix4 s) {
	translation = t;
	rotation = r;
	scale = s;
}


/* Destructor */
Particle::~Particle(void) {
}

/* GetMeshID */
string Particle::GetMeshID(void) {
	return meshID;
}


