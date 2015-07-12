/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Firework.h"

/* Constructor */
Firework::Firework(void) : Particle() {
	meshID = "Cube";
	scale = Mat4::Scale(0.1f);
	fuseTime = 0;
}

/* Constructor */
Firework::Firework(Vector4 pos, Vector4 vel, Vector4 accel, float m, float fuse) : Particle(pos, vel, accel, m) {
	meshID = "Cube";
	scale = Mat4::Scale(0.1f);

	fuseTime = fuse;
}

/* Update */
bool Firework::Update(float deltaTime){
	Particle::Update(deltaTime);

	fuseTime -= deltaTime;
	return(fuseTime > 0);
}
