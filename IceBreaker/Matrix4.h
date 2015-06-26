/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef MATRIX4
#define MATRIX4

#include <string>
#include "Vector3.h"
#include "Vector4.h"

using namespace std;

class Matrix4
{
	double PI;

public:
	 float matrix[4][4];

	/* Constructor */
	/*  float num: diagonal values */
	Matrix4(float num = 0);

	/* Constructor */
	/*	bool position: true if position, false if direction */
	Matrix4(bool position);

	/* Destructor */
	~Matrix4(void);

	/* Print */
	/*  Returns readable version of Matrix4 to as string */
	string Print(void);

	/* Operator Overloads */
	float* operator [] (int index);
	Vector4& operator * (Vector4& vec);
	Matrix4 operator * (Matrix4& mat);
};

namespace Mat4 {
	/* Translate */
	/*  Translates matrix */
	/*	float xyz: degree of translation to translate */
	Matrix4 Translate(float x, float y, float z);

	/* Rotate */
	/*  Returns vector rotated around specified axis */
	/*  Vector3& axis: axis to rotate around */
	/*  float angle: degree to rotate in radians */
	Matrix4 Rotate(Vector3& axis, float angle);

	/* Scale */
	/*  Scales matrix  */
	/*  Vector4& vec: amout to scale */
	Matrix4 Scale(Vector4& vec);

	/* LookAt */
	/*  Returns matrix containing transform data to point one vector at another */
	/*  Vector4& eye: camera position */
	/*	Vector4& point: point to look at */
	/*  Vector4& up: up-direction of camera */
	Matrix4 LookAt(Vector4& eye, Vector4& point, Vector4& _up);

	/* Perspective */
	Matrix4 Perspective(float fovy, float aspect, float zNear, float zFar);
}
#endif