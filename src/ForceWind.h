#ifndef FORCEWIND_H
#define FORCEWIND_H

#include "ofMain.h"
#include "v3.h"

class ForceWind
{
private:
	v3 pos;						
	v3 force;							
	ofMaterial material;
	ofConePrimitive cone;
	ofIcoSpherePrimitive sphere;
	float radius;

public:
	ForceWind(v3 posvec, v3 fvec, float r);
	virtual ~ForceWind();

	v3 getPosition();
	void setPosition(v3 posvec);

	v3 getForce();
	void setForce(v3 fvec);

	float getRadius();
	void setRadius(float r);

	void draw();
};

#endif