/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef REGISTRY
#define REGISTRY

#include <vector>
#include "GLShaderData.h"

/* Registry */
/*  ** Parent class for code dealing with containing libraries of various GL Shader information */
class Registry
{
protected:
	vector<GLShaderData*> registry; // Contains various shader data

public:
	/* Constructor */
	Registry(void);

	/* Desructor */
	~Registry(void);

	/* AddElement */
	/*  ** Adds GLShaderData to registry */
	/*  **** GLShaderData* sData: ShaderData to add */
	virtual void AddElement(GLShaderData* sData);
};
#endif

