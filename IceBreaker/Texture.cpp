/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Texture.h"

/* Constructor */
Texture::Texture(string _ID, GLuint bID, int nIndicies, GLuint uvArray[], int uvArraySize) : GLShaderData(_ID, bID, nIndicies) {
	for(int i = 0; i < uvArraySize; i++) {
		textureUV[i] = uvArray[i];
	}
}

/* Destructor */
Texture::~Texture(void) {
}
