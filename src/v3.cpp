#include "v3.h"

v3::v3()
{
	randomize();
}

v3::v3(float xIn, float yIn, float zIn)
{
	x = xIn;
	y = yIn;
	z = zIn;
}

void v3::randomize()
{
	x = (float)rand() / (float)RAND_MAX;
	y = (float)rand() / (float)RAND_MAX;
	z = (float)rand() / (float)RAND_MAX;
}

v3::~v3()
{
}
