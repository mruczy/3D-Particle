#ifndef OGNISKO_H
#define OGNISKO_H

#include "ofMain.h"
#include "v3.h"
#include "Object.h"


class Ognisko : public Object
{
private:
	ofMaterial materiala;
	ofMaterial materialb;
	ofConePrimitive cone;
	std::vector<ofIcoSpherePrimitive*> sphere;

public:
	Ognisko(v3 posvec);
	virtual ~Ognisko();

	void draw();
};

#endif