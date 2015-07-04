/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Registry.h"

/* Constructor */
Registry::Registry(void) {
	registry = vector<GLShaderData*>();
}

/* Destructor */
Registry::~Registry(void) {
}

/* AddElement */
void Registry::AddElement(GLShaderData* sData) {
	if(sData != nullptr) {
		registry.push_back(sData);
	}
}
