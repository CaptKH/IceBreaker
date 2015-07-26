/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef PARTICLE
#define PARTICLE

#include <string>
#include "Matrix4.h"
#include "Constants.h"

using namespace std;

class Particle
{
protected:
	string meshID;
	Vector4 forceAccum;

public:
	Vector4 position;
	Vector4 velocity;
	Vector4 acceleration;

	Vector4 minVelocity;
	Vector4 maxVelocity;

	Matrix4 rotation;
	Matrix4 scale;

	float mass;
	float inverseMass;
	float damping;
	float opacity;

	/* Default Constructor */
	Particle(void);

	/* Constructor */
	/*  **** Vector4 pos: Position */
	/*  **** Vector4 vel: Velocity */
	/*  **** Vector4 accel: Acceleration */
	/*  **** float m: Mass */
	Particle(Vector4 pos, Vector4 vel, Vector4 accel, float m);

	/* Destructor */
	~Particle(void);

	/* TransformMatrix */
	/*  ** Returns transform matrix of particle */
	Matrix4 TransformMatrix(void);

	/* Translation */
	/*  ** Returns translation matrix */
	Matrix4 Translation(void);

	/* GetMeshID */
	/*  Returns MeshID */
	string GetMeshID(void);

	/* Update */
	/*  ** Updates particle postion & state */
	/*  **** double deltaTime: Time since last frame */
	virtual void  Update(double deltaTime);

	/* Integrate */
	/*  ** Updates particles position and velocity based off of external forces */
	/*  **** float deltaTime: Amount of time to integrate over */
	virtual void Integrate(float deltaTime);

	/* AddForce */
	/*  ** Adds force to the aggregate of forces acting on the particle */
	/*  **** Vector4 force: Force to be added */
	void AddForce(Vector4 force);

private:
	/* CheckVelocity */
	/*  ** Checks to see if current velocity is less than the minimum, */
	/*  ** or greater than the maximum, and adjusts accordingly */
	void CheckVelocity(void);
};
#endif

