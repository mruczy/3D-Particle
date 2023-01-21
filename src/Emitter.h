#ifndef EMITTER_H
#define EMITTER_H

#include "v3.h"
#include "Particle.h"
#include "Generator.h"



class Emitter
{
private:
	string name = "";
	v3 pos;
	ofMaterial material;
	ofSpherePrimitive sphere;
	std::vector<Generator*> generator;

public:
	Emitter(v3 posvec, string name);
	virtual ~Emitter();

	string getName();
	void setName(string newName);

	v3 getPosition();
	void setPosition(v3 posvec);

	void addGenerator(v3 posvec, v3 fvec, float g, int amount, float radius, float mass, int life, int resolution, const ofColor_<unsigned char> color);
	//void deleteGenerator();

	std::vector<Generator*> getGenerator();

	void draw();
};

#endif