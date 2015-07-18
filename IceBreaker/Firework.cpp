/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Firework.h"

/* Constructor */
Firework::Firework(void) : Particle() {
	meshID = "Cube";
	scale = Mat4::Scale(0.05f);
	fuseTime = 0;
	type = FireworkType::INITIAL;
}

/* Constructor */
Firework::Firework(Vector4 pos, Vector4 vel, Vector4 accel, float m, float fuse) : Particle(pos, vel, accel, m) {
	meshID = "Cube";
	scale = Mat4::Scale(0.05f);
	fuseTime = fuse;
	type = FireworkType::INITIAL;
}

/* Update */
bool Firework::Update(float deltaTime){
	Particle::Update(deltaTime);

	switch(type) {
	case FireworkType::INITIAL:
			rotation = rotation * Mat4::Rotate(Vector3(0, 1, 0), 0.05f);
			break;
	}

	fuseTime -= deltaTime;
	return(fuseTime > 0);
}
