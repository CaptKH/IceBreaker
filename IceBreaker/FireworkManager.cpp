/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "FireworkManager.h"

/* Constructor */
FireworkManager::FireworkManager(void) {
	generators = vector<FireworkGenerator*>();
}

/* Destructor */
FireworkManager::~FireworkManager(void) {
}

/* Update */
void FireworkManager::Update(float deltaTime) {
	vector<FireworkGenerator*> stillActive = vector<FireworkGenerator*>();

	for(FireworkGenerator* fwg : generators) {
		if(!fwg->Update(deltaTime)) {
			delete fwg;
		}
		else {
			stillActive.push_back(fwg);
		}
	}

	generators = stillActive;
}
