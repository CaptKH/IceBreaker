/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "AnchoredSpringGenerator.h"

/* Constructor */
AnchoredSpringGenerator::AnchoredSpringGenerator(Vector4 a, float sC, float rL) {
	anchor = a;
	springConstant = sC;
	restLength = rL;
}

/* Destructor */
AnchoredSpringGenerator::~AnchoredSpringGenerator(void) {
}

/* Update */
void AnchoredSpringGenerator::Update(Particle* p, float deltaTime) {
	Vector4 force = p->position - anchor;
	float magnitude = force.Magnitude();

	magnitude = fabsf(magnitude = restLength);
	magnitude *= springConstant;

	force.Normalize();
	force *= -magnitude;
	if(magnitude == 0) {
		printf("LOL");
	}

	p->AddForce(force);
}
