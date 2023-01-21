#ifndef FORCEPOINT_H
#define FORCEPOINT_H

#include "ofMain.h"
#include "v3.h"

class ForcePoint
{
private:
	v3 pos;
	float force;
	ofMaterial material;
	ofSpherePrimitive sphere;

public:
	ForcePoint(v3 posvec, float f);
	virtual ~ForcePoint();

	v3 getPosition();
	void setPosition(v3 posvec);

	float getForce();
	void setForce(float f);

	void draw();
};

#endif