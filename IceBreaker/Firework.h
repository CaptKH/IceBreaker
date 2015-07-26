/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FIREWORK
#define FIRWWORK

#include "Particle.h"

enum FireworkType { INITIAL = 3, SECONDARY = 2, EXPLOSION = 1 };

/* Firework */
/*  ** Contains functionality for firework particle effects */
class Firework : public Particle
{
public:
	unsigned type; // Type of firework to draw
	float fuseTime;
	float maxYSpeed;

	/* Constructor */
	Firework(void);
	/* Constructor */
	/*  **** Vector4 pos: Position */
	/*  **** Vector4 vel: Velocity */
	/*  **** Vector4 accel: Acceleration */
	/*  **** float m: Mass */
	/*  **** float fuse: time of fuse */
	/*  **** float t: Firework type */		
	Firework(Vector4 pos, Vector4 vel, Vector4 accel, float m, float fuse, float t);

	/* Destructor */
	~Firework(void);

	/* Update */
	/*  ** Updates particle, returns true if still active, false if its fuseTime has run out */
	/*  **** float deltaTime: Time since last frame */
	bool Update(float deltaTime);
};
#endif

