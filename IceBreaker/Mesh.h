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

#include "GLShaderData.h"

using namespace std;

class Mesh : public GLShaderData
{
public:
	/* Constructor */
	/*  **** string _ID: Identification for registry */
	/*  **** GLuint bID: Location on GPU */
	/*  **** int nVertices: Number of indicies in shader data array */
	Mesh(string _ID, GLuint bID, int nIndicies);

	/* Destructor */
	~Mesh(void);

	void AddElement(GLShaderData sData);
};
#endif

