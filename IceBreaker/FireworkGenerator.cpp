/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "FireworkGenerator.h"

/* Constructor */
FireworkGenerator::FireworkGenerator(float xPos, float yPos) {
	fireworks = vector<Firework*>();

	for(int i = -2; i < 2; i++) {
		float randX = (float)(rand() % 50)/100.0f * i;
		float randY = (float)(rand() % 30 + 20)/10.0f;
		Firework* fw = new Firework(Vector4(xPos, yPos, 0), Vector4(randX, randY, 0), Vector4(0, 0, 0), 1.0f, 3);
		fw->minVelocity = Vector4(0, 0.1f, 0);
		fw->maxVelocity = Vector4(3, 10, 3);
		fireworks.push_back(fw);
	}
}

/* Destructor */
FireworkGenerator::~FireworkGenerator(void) {
}

/* Update */
bool FireworkGenerator::Update(float deltaTime) {
	vector<Firework*> stillActive = vector<Firework*>();

	for(Firework* f : fireworks) {
		if(!f->Update(deltaTime))
			BlowUp(f);
		else
			stillActive.push_back(f);
	}

	if(stillActive.size() > 0) {
		fireworks = stillActive;
		return true;
	}
	else {
		fireworks.clear();
		return false;
	}
}

/* BlowUp */
void FireworkGenerator::BlowUp(Firework* fw) {
	unsigned type = fw->type - 1;
	unsigned numToSpawn = 0;

	switch(type) {
	}
}
