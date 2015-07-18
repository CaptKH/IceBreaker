/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Particle.h"

/* Default Constructor */
Particle::Particle(void) {
	meshID = "Cube";

	rotation = Matrix4(1.0f);
	scale = Matrix4(1.0f);

	position = Vector4();
	velocity = Vector4(0, 0, 0);
	acceleration = Vector4();

	minVelocity = Vector4();
	maxVelocity = Vector4();

	mass = 0;
	inverseMass = 0;

	damping = 0.98f;
}

/* Constructor */
Particle::Particle(Vector4 pos, Vector4 vel, Vector4 accel, float m) {
	meshID = "Cube";

	rotation = Matrix4(1.0f);
	scale = Matrix4(1.0f);

	position = pos;
	velocity = vel;
	acceleration = accel;

	mass = m;
	inverseMass = 1/m;

	damping = 0.99f;
}


/* Destructor */
Particle::~Particle(void) {
}

/* TransformMatrix */
Matrix4 Particle::TransformMatrix(void) {
	Matrix4 translation = Translation();
	Matrix4 toReturn = translation * rotation * scale;
	return toReturn;
}

/* Translation */
Matrix4 Particle::Translation(void) {
	Matrix4 translation = Mat4::Translate(position);
	return translation;
}

/* GetMeshID */
string Particle::GetMeshID(void) {
	return meshID;
}

/* Update */
void Particle::Update(double deltaTime) {
	Integrate(deltaTime);
}

/* Integrate */
void Particle::Integrate(float duration) {
	// p = (v*t) + (1/2 * a * t^2)
	position += velocity * duration + (acceleration * duration * duration * 0.5f);

	CheckVelocity();

	// Impose damping 
	velocity *= damping;
}

/* CheckVelocity */
void Particle::CheckVelocity(void) {
	if(velocity.x < minVelocity.x) velocity.x = minVelocity.x;
	if(velocity.x > maxVelocity.x) velocity.x = maxVelocity.x;

	if(velocity.y < minVelocity.y) velocity.y = minVelocity.y;
	if(velocity.y > maxVelocity.y) velocity.y = maxVelocity.y;

	if(velocity.z < minVelocity.z) velocity.z = minVelocity.z;
	if(velocity.z > maxVelocity.z) velocity.z = maxVelocity.z;
}

/* AddForce */
void Particle::AddForce(Vector4 force) {
	forceAccum += force;
}


