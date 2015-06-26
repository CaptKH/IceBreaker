/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef VECTOR3
#define VECTOR3

#include <string>

using namespace std;

/* Vector3 */
/*	Contains functionality necessary to perform 3D vector operations */
class Vector3
{
public:
	float x; // X-coordinate in Cartesian space
	float y; // Y-coordinate in Cartesian space
	float z; // Z-coordinate in Cartesian space

	/* Constrcutor */
	/*	float _x: X-coordinate */
	/*	float _y: Y-coordinate */
	/*	float _z: Z-coordinate */
	Vector3(float _x = 0, float _y = 0, float _z = 0);

	/* Destructor */
	~Vector3(void);

	/* Magnitude */
	/*	Returns the magnitude of the vector */
	float Magnitude(void);

	/* Normalize */
	/*	Normalizes vector */
	void Normalize(void);

	/* DotProduct */
	/*	Returns the dot product between other vector */
	/*		Vector3 vec: vector needed for calculation */
	float DotProduct(Vector3& vec);

	/* AngleBetween */
	/*	Returns the angle between other vector in radians */
	/*		Vector3 vec: vector needed for calculation */
	float AngleBetween(Vector3& vec);
	
	/* CrossProduct */
	/*	Returns the cross product between other vector */
	/*		Vector3 vec: vector needed for calculation */
	Vector3 CrossProduct(Vector3& vec);

	/* Print */
	/*	Returns readable string representation of Vector3 */
	string Print(void);

	/* Operator Overloads */
	Vector3 operator + (Vector3& vec);
	Vector3 operator - (Vector3& vec);
	Vector3 operator * (float num);
	Vector3 operator / (float num);
	void operator += (Vector3& vec);
	void operator -= (Vector3& vec);
	void operator *= (float num);
	void operator /= (float num);
};
#endif
