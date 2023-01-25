#include "Plane.h"

Plane::Plane(v3 posvec)
{
	this->setPosition(posvec);
	plane.set(1000, 1000);
	plane.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	plane.rotateDeg(270, 1, 0, 0);
	this->setIsCollision(true);

	this->material.setDiffuseColor(ofFloatColor::darkGreen);
}

Plane::~Plane()
{
}

void Plane::draw()
{
	material.begin();
		plane.draw();
	material.end();
}
