#ifndef PREZENT_H
#define PREZENT_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"

class Prezent : public Object
{
public:
	ofMaterial material1;
	ofMaterial material2;
	ofMaterial material3;

	ofBoxPrimitive box1;
	ofBoxPrimitive box2;
	ofBoxPrimitive box3;

	Prezent(v3 posvec);
	virtual ~Prezent();

	void draw() override;
};

#endif