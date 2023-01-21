#include "Particle.h"

Particle::Particle(v3 posvec, v3 velvec, float radius, float mass, float g, int life, int resolution, ofColor_<unsigned char> _color)
{
	this->setPosition(posvec);
	this->setVelocity(velvec);
	this->setAcceleration(v3(0.0, 0.0, 0.0));
	this->setRadius(radius);
	this->setMass(mass);
	this->setG(g);
	this->setMaxLife(life);
	this->setLife();

	f.x = 0.0;
	f.y = 0.0;
	f.z = 0.0;

	sphere.setResolution(resolution);
	this->material.setDiffuseColor(_color);
}

Particle::~Particle()
{
}

float Particle::getRadius()
{
	return sphere.getRadius();
}

void Particle::setRadius(float radius)
{
	sphere.setRadius(radius);
}

float Particle::getMass()
{
	return m;
}

void Particle::randomMass(float minMass, float maxMass)
{
	if (maxMass > minMass && minMass > 0.0)
	{
		float tempMass = minMass + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxMass - minMass)));
		this->setMass(tempMass);
	}
}

void Particle::setMass(float mass)
{
	m = mass;
}

float Particle::getG()
{
	return g;
}

void Particle::setG(float _g)
{
	this->g = _g;
}

int Particle::getLife()
{
	return timeLife;
}

void Particle::setLife()
{
	timeLife = 0;
}

int Particle::getMaxLife()
{
	return maxLife;
}

void Particle::setMaxLife(int life)
{
	maxLife = life;
}

void Particle::updateLife()
{
	timeLife++;
}

v3 Particle::getPosition()
{
	return pos;
}

void Particle::setPosition(v3 posvec)
{
	pos.x = posvec.x;
	pos.y = posvec.y;
	pos.z = posvec.z;
}

v3 Particle::getVelocity()
{
	return vel;
}

void Particle::setVelocity(v3 velvec)
{
	vel.x = velvec.x;
	vel.y = velvec.y;
	vel.z = velvec.z;
}

v3 Particle::getAcceleration()
{
	return acc;
}

void Particle::setAcceleration(v3 accvec)
{
	acc.x = accvec.x;
	acc.y = accvec.y;
	acc.z = accvec.z;
}

v3 Particle::getForce()
{
	return f;
}

void Particle::setForce(v3 fvec)
{
	f.x = fvec.x;
	f.y = fvec.y;
	f.z = fvec.z;
}

void Particle::addForce(v3 fvec)
{
	f.x += fvec.x;
	f.y += fvec.y;
	f.z += fvec.z;
}

void Particle::updateParticle(float dt)
{
	f.y += this->getG() * m;

	//apply acceleration
	acc.x = -f.x / m;
	acc.y = -f.y / m;
	acc.z = -f.z / m;

	//apply velocity
	vel.x = vel.x + acc.x * dt;
	vel.y = vel.y + acc.y * dt;
	vel.z = vel.z + acc.z * dt;

	////max vel
	//float max = 100;

	//if (vel.x > max) vel.x = max;
	//if (vel.x < -max) vel.x = -max;
	//if (vel.y > max) vel.y = max;
	//if (vel.y < -max) vel.y = -max;

	//apply possition
	pos.x = pos.x + vel.x * dt;
	pos.y = pos.y + vel.y * dt;
	pos.z = pos.z + vel.z * dt;

	this->sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);

	f.x = 0.0;
	f.y = 0.0;
	f.z = 0.0;

	this->updateLife();
}


void Particle::draw()
{
	material.begin();
	sphere.draw();
	material.end();
}
