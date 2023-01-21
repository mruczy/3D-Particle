#ifndef OBJECT_H
#define OBJECT_H

#include "ofMain.h"
#include "v3.h"

class Object
{
protected:
	v3 pos;

public:
	Object();
	virtual ~Object();

	v3 getPosition();
	void setPosition(v3 posvec);

	virtual void draw();
};

#endif