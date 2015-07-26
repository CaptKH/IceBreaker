/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "GravityGenerator.h"

/* Constructor */
GravityGenerator::GravityGenerator(void){
	gravity = Vec4::Vec3to4(GRAVITY, 1);
}

/* Destructor */
GravityGenerator::~GravityGenerator(void) {
}
/* Update */
void GravityGenerator::Update(Particle* p, float deltaTime) {
	if(p->mass == 0) return;

	p->AddForce(gravity * p->mass);
}