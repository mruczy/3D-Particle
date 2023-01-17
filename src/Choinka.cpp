#include "Choinka.h"

Choinka::Choinka(v3 posvec)
{
	this->setPosition(posvec);
	this->cone1.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->cone2.setPosition(this->getPosition().x, this->getPosition().y + 40, this->getPosition().z);
	this->cone3.setPosition(this->getPosition().x, this->getPosition().y + 70, this->getPosition().z);

	this->cone1.setHeight(70);
	this->cone2.setHeight(60);
	this->cone3.setHeight(50);

	this->cone1.setRadius(40);
	this->cone2.setRadius(30);
	this->cone3.setRadius(20);

	this->cone1.rotateDeg(180, 1, 0, 0);
	this->cone2.rotateDeg(180, 1, 0, 0);
	this->cone3.rotateDeg(180, 1, 0, 0);
	this->material.setDiffuseColor(ofFloatColor::darkGreen);
}

Choinka::~Choinka()
{
}

void Choinka::draw()
{
	material.begin();
		cone1.draw();
		cone2.draw();
		cone3.draw();
	material.end();
}
