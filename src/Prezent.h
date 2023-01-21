#ifndef PREZENT_H
#define PREZENT_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"

class Prezent : public Object
{
private:
	ofMaterial material1;
	ofMaterial material2;
	ofMaterial material3;

	ofBoxPrimitive box1;
	ofBoxPrimitive box2;
	ofBoxPrimitive box3;

public:
	Prezent(v3 posvec);
	virtual ~Prezent();

	void draw() override;
};

#endif