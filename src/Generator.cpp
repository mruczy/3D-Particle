#include "Generator.h"
#include <random>

Generator::Generator(v3 posvec, v3 velvec, float g, int amount, float radius, float mass, int life, int resolution, ofColor_<unsigned char> _color)
{
	this->setPosition(posvec);
	this->setVelocity(velvec);
	this->setG(g);
	this->setAmount(amount);
	this->setRadius(radius);
	this->setMass(mass);
	this->setLife(life);
	this->setResolution(resolution);

	this->sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->material.setDiffuseColor(ofFloatColor::darkGreen);

	this->sphere.setRadius(10);
	this->sphere.setResolution(2);
	this->color.set(_color);
}

Generator::~Generator()
{
}

v3 Generator::getPosition()
{
	return pos;
}

void Generator::setPosition(v3 posvec)
{
	this->pos = posvec;
}

v3 Generator::getVelocity()
{
	return vel;
}

void Generator::setVelocity(v3 velvec)
{
	this->vel = velvec;
}

float Generator::getG()
{
	return g;
}

void Generator::setG(float _g)
{
	this->g = _g;
}

int Generator::getAmount()
{
	return amount;
}

void Generator::setAmount(int newAmount)
{
	this->amount = newAmount;
}

float Generator::getRadius()
{
	return radius;
}

void Generator::setRadius(float _radius)
{
	this->radius = _radius;
}

float Generator::getMass()
{
	return mass;
}

void Generator::setMass(float _mass)
{
	this->mass = _mass;
}

int Generator::getLife()
{
	return life;
}

void Generator::setLife(int _life)
{
	this->life = _life;
}

int Generator::getResolution()
{
	return resolution;
}

void Generator::setResolution(int _resolution)
{
	this->resolution = _resolution;
}

ofColor_<unsigned char> Generator::getColor()
{
	return this->color;
}

void Generator::generate(vector<Particle*>* particle, int rd)
{
	for (int i = 0; i < amount;i++)
	{
		particle->push_back(new Particle(v3(this->getPosition().x + random(-rd, rd), this->getPosition().y, this->getPosition().z + random(-rd, rd)), this->getVelocity(), getRadius(), getMass(), getG(), getLife(), getResolution(), getColor()));
	}
}

float Generator::random(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

void Generator::draw()
{
	material.begin();
	sphere.draw();
	material.end();
}
