/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef TEXTURE_REGISTRY
#define TEXTURE_REGISTRY

#include <vector>
#include "Texture.h"

/* TextureRegistry */
/*  ** Library for various textures used in the IceBreaker engine */
class TextureRegistry
{
	vector<Texture*> registry;

public:
	/* Constructor */
	TextureRegistry(void);

	/* Destructor */
	~TextureRegistry(void);

	/* AddTexture */
	/*  ** Adds texture to registry */
	/*  **** Texture* toAdd: Well duh */
	Texture* AddTexture(Texture* toAdd);

	/* GetTexture */
	/*  ** Returns specified Texture from registry */
	/*  **** string id: ID of texture to find */
	Texture* GetTexture(string id);
};
#endif

