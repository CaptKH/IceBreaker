/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef BRIDGE_MAKER
#define BRIDGE_MAKER

#include <vector>
#include "ForceManager.h"

class BridgeMaker
{
public:
	vector<Particle*> bridgePieces;

	/* Constructor */
	BridgeMaker(unsigned numPieces, Vector4 leftAnchor, Vector4 rightAnchor);

	/* Destructor */
	~BridgeMaker(void);

	/* Update */
	/*  ** Updates bridge pieces */
	void Update(float deltaTime);
};
#endif

