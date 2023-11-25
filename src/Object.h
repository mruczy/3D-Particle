#ifndef OBJECT_H
#define OBJECT_H

#include "ofMain.h"
#include "v3.h"

class Object
{
protected:
	v3 pos;
	bool collision = false;

public:
	Object();
	virtual ~Object();

	v3 getPosition();
	void setPosition(v3 posvec);

	bool getIsCollision();
	void setIsCollision(bool _collision);

	virtual void draw();
};

#endif