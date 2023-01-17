#ifndef V3_H
#define V3_H

#include <math.h>
#include <stdlib.h>

class v3
{
public:
	float x;
	float y;
	float z;

	v3();
	v3(float xIn, float yIn, float zIn);
	void randomize();
	virtual ~v3();
};

#endif