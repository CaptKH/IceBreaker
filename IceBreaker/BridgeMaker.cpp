/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "BridgeMaker.h"

/* Constructor */
BridgeMaker::BridgeMaker(unsigned numPieces, Vector4 leftAnchor, Vector4 rightAnchor) {
	bridgePieces = vector<Particle*>();

	float xDistance  = rightAnchor.x - leftAnchor.x;
	xDistance /= (numPieces);

	float i = -(numPieces/2.0f) + 0.5f;

	for( ; i < numPieces/2 + 0.5f; i++) {
		Particle* toAdd = new Particle(Vector4(xDistance * i), Vector4(), Vector4(), 0.001f);
		toAdd->minVelocity = Vector4(-0.5f, -0.5f, 0.0f);
		toAdd->maxVelocity = Vector4(0.5f, 0.5f, 0.0f);
		toAdd->scale = Mat4::Scale(xDistance * 1.5f);
		bridgePieces.push_back(toAdd);
	}


	ForceManager* fManager = ForceManager::GetInstance();

	float sC = 0.5f;

	for(int i = 0; i < bridgePieces.size(); i++) {
		
		if(i == 0) fManager->Add(bridgePieces[i], new SpringGenerator(bridgePieces[i+1], sC, xDistance/2));
		else if(i == bridgePieces.size() - 1) fManager->Add(bridgePieces[i], new SpringGenerator(bridgePieces[i-1], sC, xDistance/2));
		else {
			fManager->Add(bridgePieces[i], new SpringGenerator(bridgePieces[i-1], sC, xDistance/2));
			fManager->Add(bridgePieces[i], new SpringGenerator(bridgePieces[i+1], sC, xDistance/2));
		}

		//fManager->Add(bridgePieces[i], new BuoancyGenerator(0.3f, 0.027, 0.5f, 10.0f));
		

		fManager->Add(bridgePieces[i], fManager->gravity);
	}
}

/* Destructor */
BridgeMaker::~BridgeMaker(void) {
	for(Particle* p : bridgePieces) {
		p = nullptr;
		delete p;
	}

	bridgePieces.clear();
}

/* Update */
void BridgeMaker::Update(float deltaTime) {
	for(int i = 1; i < bridgePieces.size() - 1; i++) {
		bridgePieces[i]->Update(deltaTime);
	}
}
