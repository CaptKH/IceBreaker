/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FORCE_MANAGER
#define FORCE_MANAGER

#include <vector>
#include "Constants.h"
#include "GravityGenerator.h"
#include "DragGenerator.h"

class ForceManager
{
protected:
	struct ForceRegistration {
		Particle* p;
		ForceGenerator* fGenerator;
	};

	vector<ForceRegistration*> registrations;

public:
	static ForceManager* singleton;
	GravityGenerator* gravity;
	DragGenerator* drag;

	/* GetInstance */
	/*  ** Returns singleton */
	static ForceManager* GetInstance(void);

	/* Add */
	/*  ** Pushes new particle being affected by specified force onto registrations list */
	void Add(Particle* _p, ForceGenerator* fGen);

	/* Remove */
	/*  ** Removes specified particle and force generator from registrations list */
	void Remove(Particle* _p);

	/* Clear */
	/*  ** Clear registrations list */
	void Clear(void);

	/* Update */
	/*  ** Updates all particles currently being affected by forces */
	void Update(float deltaTime);

	/* CleanUp */
	/*  ** Removes any particles that no longer exist */
	void CleanUp(void);

private: 
	/* Constructor */
	ForceManager(void);

	/* Destructor */
	~ForceManager(void);
};
#endif

