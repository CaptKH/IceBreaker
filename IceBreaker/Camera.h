/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef CAMERA
#define CAMERA

#include "Matrix4.h"
#include <iostream>

class Camera
{
public:
	Vector4 position;	// Location of camera in world space
	Vector4 direction;  // Direction camera us facing
	Vector4 up;			// Up vector of camera
	Vector4 right;		// Right vector of camera

	float hAngle;		// Horizontal angle of camera
	float vAngle;		// Vertical angle of camera
	float initialFoV;

	float speed;
	float mouseSpeed;

	/* Constructor */
	/*  ** Vector4& pos: initlial position of camera in world space */
	Camera(Vector4& pos);

	/* Destructor */
	~Camera(void);
	
	/* Update */
	/*  ** Updates camera positions based on user input and returns current view matrix */
	/*  **** int windowWidth: Window width */
	/*  **** int windowHeight: Window height */
	/*  **** double mouseX: Mouse x-position in window */
	/*  **** double mouseY: Mouse y-position in window */
	/*  **** double deltaTime: Time since last frame */
	Matrix4& Update(int windowWidth, int windowHeight, double mouseX, double mouseY, double deltaTime);
	
};
#endif

