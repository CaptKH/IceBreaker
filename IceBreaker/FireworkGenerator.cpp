/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "FireworkGenerator.h"

/* Constructor */
FireworkGenerator::FireworkGenerator(float xPos, float yPos) {
	fireworks = vector<Firework*>();

	ForceManager* fManager = ForceManager::GetInstance();

	for(float i = -2; i < 3; i += 0.9f) {
		float randX = (float)(rand() % 20 + 20)/100.0f * i;
		float randY = (float)(rand() % 10 + 15)/10.0f;
		Firework* fw = new Firework(Vector4(xPos, yPos, 0), Vector4(randX, randY, 0), Vector4(0, 0, 0), 0.3f, 1.0f, FireworkType::INITIAL);
		fw->minVelocity = Vector4(-0.2f, -2.0f, 0);
		fw->maxVelocity = Vector4(0.2f, 10, 3);
		fireworks.push_back(fw);
		fManager->Add(fw, fManager->gravity);
	}
}

/* Destructor */
FireworkGenerator::~FireworkGenerator(void) {
}

/* Update */
bool FireworkGenerator::Update(float deltaTime) {
	for(Firework* f : fireworks) {
		if(!f->Update(deltaTime)) {
			BlowUp(f);
			//ForceManager::GetInstance()->Remove(f);
			f = nullptr;
		}
		else {
			nextFrame.push_back(f);
		}
	}

	fireworks = nextFrame;
	nextFrame.clear();

	return (fireworks.size() > 0);
}

void FireworkGenerator::BlowUp(Firework* fw) {
	unsigned type = fw->type - 1;
	unsigned numToSpawn = 0;

	switch(type) {
	case FireworkType::SECONDARY:
		ForceManager* fManager = ForceManager::GetInstance();
		
		numToSpawn = 20 + rand() % 20;
		for(unsigned i = 0; i < numToSpawn; i++) {
			float randSpeed = (10 + rand() % 10)/20.0f;
			Firework* toAdd = new Firework(fw->position, Vec4::Normalize(Vec4::Random()) * randSpeed, Vector4(), 0.06f, 1.5f, type);

			toAdd->minVelocity = Vector4(-1.0f, -3.0f, 0);
			toAdd->maxVelocity = Vector4(3.0f, 3.0f, 3);
			nextFrame.push_back(toAdd);
			fManager->Add(toAdd, fManager->gravity);
		}

		break;
	}
}
