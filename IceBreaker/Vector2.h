/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef VECTOR2
#define VECTOR2

#include <string>

using namespace std;

/* Vector2 */
/*	Contains functionality necessary to perform 2D vector operations */
class Vector2
{
	float x; // X-coordinate in Cartesian space
	float y; // Y-coordinate in Cartesian space

public:
	/* Constructor */
	/*	float _x: X-coordinate */
	/*	float _y: Y-coordinate */
	Vector2(float _x = 0, float _y = 0);

	/* Destructor */
	~Vector2(void);

	/* Magnitude */
	/*	Returns the magnitude of the vector */
	float Magnitude(void);

	/* Normalize */
	/*	Normalizes vector */
	void Normalize(void);

	/* DotProduct */
	/*	Returns the dot product between other vector */
	/*		Vector2 vec: vector needed for calculation */
	float DotProduct(Vector2& vec);

	/* AngleBetween */
	/*	Returns the angle between other vector in radians */
	/*		Vector2 vec: vector needed for calculation */
	float AngleBetween(Vector2& vec);

	/* Print */
	/*	Returns readable string representation of Vector2 */
	string Print(void);

	/* Operator Overloads */
	Vector2 operator + (Vector2& vec);
	Vector2 operator - (Vector2& vec);
	Vector2 operator * (float num);
	Vector2 operator / (float num);
	void operator += (Vector2& vec);
	void operator -= (Vector2& vec);
	void operator *= (float num);
	void operator /= (float num);
};
#endif

