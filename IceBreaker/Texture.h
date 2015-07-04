/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef TEXTURE
#define TEXTURE

#include "GLShaderData.h"

using namespace std;

/* Texture */
class Texture : public GLShaderData
{
public:
	GLuint textureUV[];

	/* Constructor */
	/*  **** string _ID: Identification for registry */
	/*  **** GLuint bID: Location on GPU */
	/*  **** int nVertices: Number of indicies in shader data array */
	/*  **** GLuint uvArray: Array of texture UV's */
	/*  **** int uvArraySize: Size of UV array */
	Texture(string _ID, GLuint bID, int nIndicies, GLuint uvArray[], int uvArraySize);

	/* Destructor */
	~Texture(void);
};
#endif

