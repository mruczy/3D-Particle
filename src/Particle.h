#ifndef PARTICLE_H
#define	PARTICLE_H

#include "ofMain.h"
#include "v3.h"

class Particle
{
private:
	float r;		//radius
	float m;		//mass
	int timeLife;
	int maxLife;
	v3 pos;			//position vector
	v3 vel;			//veloticy vector
	v3 acc;			//acceleration vector
	v3 f;           //force vector
	ofMaterial material;
	ofIcoSpherePrimitive sphere;

public:
	Particle(v3 posvec, v3 velvec, float radius, float mass, int life);
	virtual ~Particle();

	float getRadius();
	void setRadius(float radius);

	float getMass();
	void randomMass(float minMass, float maxMass);
	void setMass(float mass);

	int getLife();
	void setLife();
	int getMaxLife();
	void setMaxLife(int life);
	void updateLife();

	v3 getPosition();
	void setPosition(v3 posvec);

	v3 getVelocity();
	void setVelocity(v3 velvec);

	v3 getAcceleration();
	void setAcceleration(v3 accvec);

	v3 getForce();
	void setForce(v3 fvec);
	void addForce(v3 fvec);

	void updateParticle(float dt);

	void draw();
};

#endif