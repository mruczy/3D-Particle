#include "Object.h"

Object::Object()
{
	this->setIsCollision(false);
}

Object::~Object()
{
}

v3 Object::getPosition()
{
	return pos;
}

void Object::setPosition(v3 posvec)
{
	this->pos = posvec;
}

bool Object::getIsCollision()
{
	return collision;
}

void Object::setIsCollision(bool _collision)
{
	collision = _collision;
}

void Object::draw()
{
}