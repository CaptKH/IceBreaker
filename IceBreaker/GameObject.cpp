/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "GameObject.h"

/* Constructor */
GameObject::GameObject(char* n, Matrix4& pos, GLfloat v[]) {
	name = n;
	position = pos;
}

/* Destructor */
GameObject::~GameObject(void) {
}
