/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef GL_SHADER_DATA
#define GL_SHADER_DATA

#ifndef OPEN_GL
#define OPEN_GL
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#endif

#include <string>

using namespace std;

/* GLShaderData */
/*  **** Parent class for all code containing data needed for OpenGL shaders */
class GLShaderData
{
protected:
	string ID; // Identification for registry
	GLuint bufferID; // Location on GPU
	unsigned int numIndicies; // Number of indicies in shader data array

public:
	/* Constructor */
	/*  **** string _ID: Identification for registry */
	/*  **** GLuint bID: Location on GPU */
	/*  **** int nVertices: Number of indicies in shader data array */
	GLShaderData(string _ID, GLuint bID, int nVertices);

	/* Destructor */
	~GLShaderData(void);

	/* GetID */
	/*  ** Returns ID */
	string GetID(void);

	/* GetVBO */
	/*  ** Returns vertexBuffer */
	GLuint GetVBO(void);

	/* GetNumIndicies */
	/*  ** Returns number of indicies in shader data array */
	unsigned int GetNumIndicies(void);
};
#endif

