/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "ForceManager.h"

ForceManager* ForceManager::singleton = nullptr;

/* Constructor */
ForceManager::ForceManager(void) {
	registrations = vector<ForceRegistration*>();
	gravity = new GravityGenerator();
	anchoredSpring = new AnchoredSpringGenerator(Vector4(0, 0, 0, 1), 50, 0.2);
}

/* Destructor */
ForceManager::~ForceManager(void) {
}

/* GetInstance */
ForceManager* ForceManager::GetInstance(void) {
	if(singleton == nullptr) singleton = new ForceManager();

	return singleton;
}

/* Add */
void ForceManager::Add(Particle* _p, ForceGenerator* fGen) {
	ForceRegistration* toAdd = new ForceRegistration();
	toAdd->p = _p;
	toAdd->fGenerator = fGen;

	registrations.push_back(toAdd);
}

/* Remove */
void ForceManager::Remove(Particle* _p) {
	int toErase = 0;

	while(true) {
		for(ForceRegistration* fRegistration : registrations) {
			if(fRegistration->p == _p) {
				break;
			}
			else toErase++;
		}

		if(toErase < registrations.size()) {
			registrations.erase(registrations.begin() + toErase);
			toErase = 0;
		}
		else break;
	}
}

/* Clear */
void ForceManager::Clear(void) {
	registrations.clear();
}

/* Udpate */
void ForceManager::Update(float deltaTime) {
	for(ForceRegistration* r : registrations) {
		r->fGenerator->Update(r->p, deltaTime);
	}
}

/* CleanUp */
void ForceManager::CleanUp(void) {
	vector<ForceRegistration*> stillActive = vector<ForceRegistration*>();

	for(ForceRegistration* fReg : registrations) {
		if(fReg->p != nullptr) stillActive.push_back(fReg);
		else {
			delete fReg;
		}
	}

	registrations = stillActive;
}
