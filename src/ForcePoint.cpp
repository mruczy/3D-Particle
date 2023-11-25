#include "ForcePoint.h"

ForcePoint::ForcePoint(v3 posvec, float f)
{
	this->setPosition(posvec);
	this->setForce(f);
	sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	material.setDiffuseColor(ofFloatColor::blue);

	sphere.setRadius(20);
	sphere.setResolution(2);
}

ForcePoint::~ForcePoint()
{
}

v3 ForcePoint::getPosition()
{
	return pos;
}

void ForcePoint::setPosition(v3 posvec)
{
	this->pos = posvec;
}

float ForcePoint::getForce()
{
	return force;
}

void ForcePoint::setForce(float f)
{
	this->force = f;
}

void ForcePoint::draw()
{
	material.begin();
	sphere.draw();
	material.end();
}
