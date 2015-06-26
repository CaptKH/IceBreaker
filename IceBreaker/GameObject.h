/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "Matrix4.h"
#include <GL/glew.h>

class GameObject
{
	char* name;
	Matrix4 position;
	GLfloat vertices[];

public:
	/* Constructor */
	GameObject(char* n, Matrix4& pos, GLfloat v[]);

	/* Destructor */
	~GameObject(void);
};
#endif
