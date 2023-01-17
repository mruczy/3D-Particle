#ifndef EMITTER_H
#define EMITTER_H

#include "v3.h"
#include "ofMain.h"
#include "Particle.h"
#include "Generator.h"



class Emitter
{
public:

	v3 pos;
	int spawnTimer;
	int counter;
	ofMaterial material;
	ofSpherePrimitive sphere;

	Emitter(v3 posvec);
	virtual ~Emitter();

	v3 getPosition();
	void setPosition(v3 posvec);

	//int getSpawnTimer();
	//void setSpawnTimer(int spawntimer);

	//int getCounter();
	//void setCounter(int ct);
	//void Counter();

	void draw();
	float rd(float min, float max);

	void generate(vector<Particle*> *particle);
};

#endif