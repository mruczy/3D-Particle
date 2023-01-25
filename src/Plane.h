#ifndef PLANE_H
#define PLANE_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"

class Plane : public Object
{
private:
	ofMaterial material;
	ofPlanePrimitive plane;

public:
	Plane(v3 posvec);
	virtual ~Plane();

	void draw();
};

#endif