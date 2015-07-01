/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef CAMERA
#define CAMERA

#include "Matrix4.h"

class Camera
{
public:
	Matrix4 position;
	Matrix4 rotation;

	/* Constructor */
	/*  Matrix4& pos: initlial position of camera in world space */
	Camera(Matrix4& pos);

	/* Destructor */
	~Camera(void);
	
	/* LookAt */
	/*	Points camera in direction of specified point */
	/*  Vector4 point: point to look at */
	Matrix4 LookAt(Vector4 point);
	
};
#endif

