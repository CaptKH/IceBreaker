/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "DragGenerator.h"

/* Constructor */
DragGenerator::DragGenerator(float _k1, float _k2) {
	k1 = _k1;
	k2 = _k2;
}

/* Destructor */
DragGenerator::~DragGenerator(void) {
}

/* Update */
void DragGenerator::Update(Particle* p, float deltaTime) {
	Vector4 force = p->velocity;

	float dragCoeff = force.Magnitude();

	dragCoeff = (k1 * dragCoeff) + (k2 * dragCoeff * dragCoeff);

	force.Normalize();
	force *= -dragCoeff;
	p->AddForce(force * p->mass);
}
