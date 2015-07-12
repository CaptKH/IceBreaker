/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "FireworkGenerator.h"

/* Constructor */
FireworkGenerator::FireworkGenerator(void) {
	fireworks = vector<Firework*>();

	srand(time(NULL));
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

	return false;
}

/* BlowUp */
void FireworkGenerator::BlowUp(Firework* fw) {
	unsigned type = fw->type - 1;
	unsigned numToSpawn = 0;

	switch(type) {
	}
}
