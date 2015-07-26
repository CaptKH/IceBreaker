/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Firework.h"

/* Constructor */
Firework::Firework(void) : Particle() {
	meshID = "Cube";
	type = FireworkType::INITIAL;
	fuseTime = 0;
	maxYSpeed = 0;
	damping = 0.98f;
}

/* Constructor */
Firework::Firework(Vector4 pos, Vector4 vel, Vector4 accel, float m, float fuse, float t) : Particle(pos, vel, accel, m) {
	meshID = "Cube";
	type = t;
	fuseTime = fuse;
	maxYSpeed = abs(vel.y);
	damping = 0.98f;

	if(type == FireworkType::SECONDARY)
		scale = Mat4::Scale(0.07f);
	else 
		scale = Mat4::Scale(0.03f);
}

/* Destructor */
Firework::~Firework(void) {
}

/* Update */
bool Firework::Update(float deltaTime, Vector3 gravity){
	Particle::Update(deltaTime, gravity);

	// Calculate rotation speed so fireworks rotate
	// faster at start and slower at the end
	float rotationSpeed = velocity.y/maxYSpeed * 50;

	rotation = Mat4::Rotate(Vector3(0, 0, 1), velocity.AngleBetween(Vector4(1, 0, 0)) * 2);
	rotation = rotation * Mat4::Rotate(Vector3(0, 1, 0), rotationSpeed);

	if(type == FireworkType::SECONDARY) {
		scale = Mat4::Scale(scale[0][0] - deltaTime/20);
		opacity -= deltaTime/2;
	}

	fuseTime -= deltaTime;
	return(fuseTime > 0);
}
