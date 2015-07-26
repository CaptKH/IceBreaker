/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FIREWORK_MANAGER
#define FIREWORK_MANAGER

#include <vector>
#include "FireworkGenerator.h"

/* FireworkManager */
/*  ** Contains functionality to perform firework particle effects */
class FireworkManager
{
public:
	vector<FireworkGenerator*> generators;

	/* Constructor */
	FireworkManager(void);

	/* Destructor */
	~FireworkManager(void);

	/* Update */
	/*  ** Updates all currently active firework generators */
	void Update(float deltaTime);
};
#endif

