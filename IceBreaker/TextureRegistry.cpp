/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "TextureRegistry.h"

/* Constructor */
TextureRegistry::TextureRegistry(void) {
	registry = vector<Texture*>();
}

/* Destructor */
TextureRegistry::~TextureRegistry(void) {
}


/* GetTexture */
Texture* TextureRegistry::GetTexture(string id) {
	for(Texture* t : registry) {
		if(t->GetID() == id)
			return t;
	}

	return nullptr;
}

/* AddTexture */
Texture* TextureRegistry::AddTexture(Texture* toAdd) {
	if(toAdd != nullptr)
		registry.push_back(toAdd);
	
	return toAdd;
}

