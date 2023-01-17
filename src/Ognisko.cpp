#include "Ognisko.h"

Ognisko::Ognisko(v3 posvec)
{
	this->setPosition(posvec);
	this->cone.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->cone.rotateDeg(180, 1, 0, 0);
	this->cone.setHeight(40);
	
	for (int d = 0; d < 360; d += 45)
	{
		this->sphere.push_back(new ofIcoSpherePrimitive());
	}

	int deg = 0;
	for (auto* sph : this->sphere)
	{
		float x = 20 * cos(deg * (PI / 180)) + this->getPosition().x;
		float z = 20 * sin(deg * (PI / 180)) + this->getPosition().z;
		sph->setPosition(x, this->getPosition().y - 20, z);
		sph->setResolution(1);
		sph->setRadius(10);
		deg += 45;
	}

	this->materiala.setDiffuseColor(ofFloatColor::brown);
	this->materialb.setDiffuseColor(ofFloatColor::darkGray);
}

Ognisko::~Ognisko()
{
}

void Ognisko::draw()
{
	materiala.begin();
	cone.draw();
	materiala.end();

	materialb.begin();
	for (auto* sph : this->sphere)
	{
		sph->draw();
	}
	materialb.end();
}
