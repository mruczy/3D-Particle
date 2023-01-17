#ifndef CHOINKA_H
#define CHOINKA_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"


class Choinka: public Object 
{
public:
	ofMaterial material;
	ofConePrimitive cone1;
	ofConePrimitive cone2;
	ofConePrimitive cone3;

	Choinka(v3 posvec);
	virtual ~Choinka();

	void draw();
};

#endif