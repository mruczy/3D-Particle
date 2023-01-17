#ifndef GENERATOR_H
#define GENERATOR_H

#include "v3.h"
#include "Particle.h"

class Generator
{
private:
	v3 pos;
	int amount;								//how many particle generate in one tick
	ofMaterial material;
	ofIcoSpherePrimitive sphere;

public:
	Generator(v3 posvec, int amount);
	virtual ~Generator();

	//get pos from emiter
	//in future get pos of primitive//
	v3 getPosition();
	void setPosition(v3 posvec);

	int getAmount();
	void setAmount(int newAmount);

	//Particle generator 
	void generate(vector<Particle*> *particle);

	float random(float min, float max);

	void draw();
};

#endif