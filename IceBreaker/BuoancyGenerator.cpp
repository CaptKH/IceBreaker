/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "BuoancyGenerator.h"

/* Constructor */
BuoancyGenerator::BuoancyGenerator(float mD, float v, float wH, float lD) {
	maxDepth = mD;
	volume = v;
	waterHeight = wH;
	liquidDensity = lD;
}

/* Destructor */
BuoancyGenerator::~BuoancyGenerator(void) {
}

/* Update */
void BuoancyGenerator::Update(Particle* p, float deltaTime) {
	Vector4 force;
	float depth = p->position.y;

	if(depth >= waterHeight + maxDepth) 
		return;
	else if(depth <= waterHeight - maxDepth) {
		force.y = liquidDensity * volume;
		p->AddForce(force);
		return;
	}
	else {
		force.y = liquidDensity * volume * ((depth - maxDepth - waterHeight) / (2 * maxDepth));
		p->AddForce(force);
		return;
	}
}
