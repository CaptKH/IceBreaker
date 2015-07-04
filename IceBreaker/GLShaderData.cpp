/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "GLShaderData.h"

/* Constructor */
GLShaderData::GLShaderData(string _ID, GLuint bID, int nIndicies) {
	ID = _ID;
	bufferID = bID;
	numIndicies = nIndicies;
}

/* Destructor */
GLShaderData::~GLShaderData(void) {
}

/* GetID */
string GLShaderData::GetID(void) {
	return ID;
}

/* GetVBO */
GLuint GLShaderData::GetVBO(void) {
	return bufferID;
}

/* GetNumIndicies */
unsigned int GLShaderData::GetNumIndicies(void) {
	return numIndicies;
}
