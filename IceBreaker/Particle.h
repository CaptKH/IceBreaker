/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef PARTICLE
#define PARTICLE

#include <string>
#include "Matrix4.h"

using namespace std;

class Particle
{
protected:
	string meshID;

public:
	/* Transformation Data */
	Matrix4 translation;
	Matrix4 rotation;
	Matrix4 scale;

	/* Default Constructor */
	Particle(void);

	/* Constructor */
	Particle(Matrix4 t, Matrix4 r, Matrix4 s);

	/* Destructor */
	~Particle(void);

	/* GetMeshID */
	/*  Returns MeshID */
	string GetMeshID(void);
};
#endif

