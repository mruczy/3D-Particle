#ifndef GENERATOR_H
#define GENERATOR_H

#include "v3.h"
#include "Particle.h"

class Generator
{
private:
	v3 pos;									
	v3 vel;									//particle start velocity
	float g;								//g force
	int amount;								//how many particle generate in one tick
	ofMaterial material;
	ofIcoSpherePrimitive sphere;

	float radius;							
	float mass;								
	int life;								
	int resolution;							
	ofColor_<unsigned char> color;			

public:
	Generator(v3 posvec, v3 fvec, float g, int amount, float radius, float mass, int life, int resolution, ofColor_<unsigned char> color);
	virtual ~Generator();

	v3 getPosition();
	void setPosition(v3 posvec);

	v3 getVelocity();
	void setVelocity(v3 fvec);

	float getG();
	void setG(float _g);

	int getAmount();
	void setAmount(int newAmount);

	float getRadius();
	void setRadius(float _radius);
	
	float getMass();
	void setMass(float _mass);

	int getLife();
	void setLife(int _life);

	int getResolution();
	void setResolution(int _resolution);

	ofColor_<unsigned char> getColor();

	void generate(vector<Particle*>* particle, int rd);

	float random(float min, float max);

	void draw();
};

#endif