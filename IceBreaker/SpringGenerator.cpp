/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "SpringGenerator.h"

/* Constructor */
SpringGenerator::SpringGenerator(Particle* p, float sC, float rL) {
	other = p;
	springConstant = sC;
	restLength = rL;
}

/* Destructor */
SpringGenerator::~SpringGenerator(void) {
}

/* Update*/
void SpringGenerator::Update(Particle* p, float deltaTime) {
	Vector4 force = p->position - other->position;
	float magnitude = force.Magnitude();

	if(other->position.x >=  100) {
		printf("MOPEO");
	}

	magnitude = fabsf(magnitude - restLength);
	magnitude *= springConstant;

	force.Normalize();
	force *= -magnitude;

	p->AddForce(force);
}
