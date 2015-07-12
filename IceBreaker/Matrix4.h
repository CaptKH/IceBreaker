/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef MATRIX4
#define MATRIX4

#include <string>
#include "Vector3.h"
#include "Vector4.h"

using namespace std;

/* Matrix4 */
/* ** Contains functionality necessary to perform 4x4 Matrix operations */
class Matrix4
{
public:
	 float matrix[4][4];
	  
	/* Constructor */
	/*  **** float num: diagonal values */
	Matrix4(float num = 0.0f);

	/* Destructor */
	~Matrix4(void);
	
	/* Transpose */
	/*  ** Transposes matrix */
	void Transpose(void);

	/* Print */
	/*  ** Returns readable version of Matrix4 to as string */
	string Print(void);

	/* Operator Overloads */
	float* operator [] (int index);
	Vector4& operator * (Vector4& vec);
	Matrix4 operator * (Matrix4& mat);
};

/* Mat4 */
/*  ** Contains numerous Matrix4 operations */
namespace Mat4 {
	/* Translate */
	/*  ** Translates matrix */
	/*	**** Vector4& pos: Amount to translate */
	Matrix4 Translate(Vector4& pos);

	/* Translate */
	/*  ** Translates matrix */
	/*	**** float xyz: degree of translation to translate */
	Matrix4 Translate(float x, float y, float z);

	/* Rotate */
	/*  ** Returns vector rotated around specified axis */
	/*  **** Vector3& axis: axis to rotate around */
	/*  **** float angle: degree to rotate in radians */
	Matrix4 Rotate(Vector3& axis, float angle);

	/* Scale */
	/*  ** Scales matrix  */
	/*  **** float s: scaling in xyz-directions */
	Matrix4 Scale(float s);

	/* Scale */
	/*  ** Scales matrix  */
	/*  **** float x: scaling in x-direction */
	/*  **** float y: scaling in y-direction */
	/*  **** float z: scaling in z-direction */
	Matrix4 Scale(float x, float y, float z);

	/* LookAt */
	/*  ** Returns matrix containing transform data to point one vector at another */
	/*  **** Vector4& eye: camera position */
	/*	**** Vector4& point: point to look at */
	/*  **** Vector4& up: up-direction of camera */
	Matrix4 LookAt(Vector4& eye, Vector4& point, Vector4& _up);

	/* Perspective */
	/*  ** Returns matrix contains projection data */
	/*  **** float fovy: frustrum */
	/*  **** float aspec: aspect ratio */
	/*  **** float zNear: near clipping plane */
	/*  **** float zFar: far clipping plane */
	Matrix4 Perspective(float fovy, float aspect, float zNear, float zFar);
}
#endif