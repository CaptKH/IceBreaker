/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "BungeeGenerator.h"

/* Constructor */
BungeeGenerator::BungeeGenerator(Particle* p, float sC, float rL) {
	other = p;
	springConstant = sC;
	restLength = rL;
}

/* Destructor */
BungeeGenerator::~BungeeGenerator(void) {
}

/* Update */
void BungeeGenerator::Update(Particle* p, float deltaTime) {
	Vector4 force = p->position - other->position;
	float magnitude = force.Magnitude();

	if(magnitude < restLength) return;

	magnitude = magnitude * (restLength - magnitude);
	force.Normalize();
	force *= magnitude;
	p->AddForce(force);
}
