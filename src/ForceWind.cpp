#include "ForceWind.h"

ForceWind::ForceWind(v3 posvec, v3 fvec, float r)
{
	this->setPosition(posvec);
	this->setForce(fvec);
	this->setRadius(r);
	cone.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	sphere.setResolution(1);
	sphere.setRadius(getRadius());
	material.setDiffuseColor(ofFloatColor::pink);
	cone.rotateDeg(90, 1, 0, 0);
}

ForceWind::~ForceWind()
{
}

v3 ForceWind::getPosition()
{
	return pos;
}

void ForceWind::setPosition(v3 posvec)
{
	this->pos = posvec;
}

v3 ForceWind::getForce()
{
	return force;
}

void ForceWind::setForce(v3 fvec)
{
	this->force = fvec;
}

float ForceWind::getRadius()
{
	return radius;
}

void ForceWind::setRadius(float r)
{
	this->radius = r;
}

void ForceWind::draw()
{
	material.begin();
		cone.draw();

		ofNoFill();
		ofSetColor(0, 0, 0);
		sphere.drawWireframe();
		ofFill();
	material.end();
}
