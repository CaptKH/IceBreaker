/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef VECTOR4
#define VECTOR4

#include <time.h>
#include <random>
#include <string>
#include "Vector3.h"

using namespace std;

/* Vector4 */
/*	** Contains functionality necessary to perform 3D Vector operations */
class Vector4
{
public:
	float x; // X-coordinate in Cartesian space
	float y; // Y-coordinate in Cartesian space
	float z; // Z-coordinate in Cartesian space
	float w; // Buffer

	/* Constrcutor */
	/*	**** float _x: X-coordinate */
	/*	**** float _y: Y-coordinate */
	/*	**** float _z: Z-coordinate */
	/*	**** float _w: Buffer */
	Vector4(float _x = 0, float _y = 0, float _z = 0, float _w = 1);

	/* Destructor */
	~Vector4(void);

	/* Clear */
	/*  ** Resets Vector4 to (0, 0, 0, w) */
	void Clear(void);

	/* Magnitude */
	/*  ** Returns the magnitude of the vector */
	float Magnitude(void);

	/* Normalize */
	/*	** Normalizes vector */
	void Normalize(void);

	/* DotProduct */
	/* 	** Returns the dot product between other vector */
	/*	**** Vector4 vec: vector needed for calculation */
	float DotProduct(Vector4& vec);

	/* AngleBetween */
	/*	** Returns the angle between other vector in radians */
	/*	**** Vector4 vec: vector needed for calculation */
	float AngleBetween(Vector4& vec);
	
	/* CrossProduct */
	/* ** Returns the cross product between other vector */
	/* ****	Vector4 vec: vector needed for calculation */
	Vector4 CrossProduct(Vector4& vec);

	/* Print */
	/* ** Returns readable string representation of Vector4 */
	string Print(void);

	/* Operator Overloads */
	Vector4 operator + (Vector4& vec);
	Vector4 operator - (Vector4& vec);
	Vector4 operator * (float num);
	Vector4 operator / (float num);
	void operator += (Vector4& vec);
	void operator -= (Vector4& vec);
	void operator *= (float num);
	void operator /= (float num);
};

namespace Vec4 {
	/* Vec3to4 */
	/*  ** Returns Vector4 representation of Vector3 */
	Vector4 Vec3to4(Vector3 vec3, int w = 0);

	/* Random */
	/*  ** Returns normalized vector pointing in random direction */
	Vector4 Random(void);

	/* Normalize */
	/*  ** Returns vector representing normalization of specified vector */
	/*  **** Vector4 toNorm: Vector4 to find normal of */
	Vector4 Normalize(Vector4 toNorm);
}
#endif
