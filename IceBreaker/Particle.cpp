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
	opacity = 1.0f;
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
	damping = 0.98f;
	opacity = 1.0f;
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
void Particle::Update(double deltaTime, Vector3 gravity) {
	// Add gravity to environment, if there is any
	AddForce(Vec4::Vec3to4(gravity, 1));

	// Move everything
	Integrate(deltaTime);

	// Clear force accumulator for next update
	forceAccum.Clear();
}

/* Integrate */
void Particle::Integrate(float duration) {
	// Add forces to acceleration
	Vector4 currentAccel = acceleration;
	currentAccel = forceAccum * mass;

	// v += a*t
	velocity += currentAccel * duration;

	// p += v*t
	position += velocity * duration;

	CheckVelocity();
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


