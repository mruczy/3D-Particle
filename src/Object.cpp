#include "Object.h"

Object::Object()
{

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

void Object::draw()
{
}