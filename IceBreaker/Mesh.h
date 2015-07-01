/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef MESH
#define MESH

#ifndef OPEN_GL
#define OPEN_GL
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#endif

#include <string>

using namespace std;

class Mesh
{
	string ID;
	GLuint vertexBuffer;
	int numIndicies;
	int numVertices;

public:
	/* Constructor */
	Mesh(string _ID, GLuint vbo, int nIndicies);

	/* Destructor */
	~Mesh(void);

	/* GetID */
	/*  Returns string ID of Mesh */
	string GetID(void);

	/* GetNumIndicies */
	/*  Returns numer of indicies in mesh */
	int GetNumIndicies(void);

	/* GetVBO */
	/*  Returns vertexBuffer of mesh */
	GLuint GetVBO(void);
};
#endif

