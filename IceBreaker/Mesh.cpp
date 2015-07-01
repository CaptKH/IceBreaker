/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Mesh.h"

/* Constructor */
Mesh::Mesh(string _ID, GLuint vbo, int nIndicies) {
	ID = _ID;
	vertexBuffer = vbo;
	numIndicies = nIndicies;
}

/* Destructor */
Mesh::~Mesh(void) {
}

/* GetID */
string Mesh::GetID(void) {
	return ID;
}

/* GetNumIndicies */
int Mesh::GetNumIndicies(void) {
	return numIndicies;
}

/* GetVBO */
GLuint Mesh::GetVBO(void) {
	return vertexBuffer;
}
