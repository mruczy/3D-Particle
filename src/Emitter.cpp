#include "Emitter.h"
#include <iostream>
#include <random>

Emitter::Emitter(v3 posvec)
{
	this->setPosition(posvec);
	this->sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->material.setDiffuseColor(ofFloatColor::green);

	this->sphere.setRadius(20);
	this->sphere.setResolution(2);
}


Emitter::~Emitter()
{
}

v3 Emitter::getPosition()
{
	return pos;
}

void Emitter::setPosition(v3 posvec)
{
	this->pos = posvec;
}

//int Emitter::getSpawnTimer()
//{
//	return spawnTimer;
//}
//
//void Emitter::setSpawnTimer(int spawntimer)
//{
//	spawnTimer = spawntimer;
//}
//
//int Emitter::getCounter()
//{
//	return counter;
//}
//
//void Emitter::setCounter(int ct)
//{
//	this->counter = ct;
//}
//
//void Emitter::Counter()
//{
//	counter++;
//}

void Emitter::draw()
{
	material.begin();
	sphere.draw();
	material.end();
}

float Emitter::rd(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

void Emitter::generate(vector<Particle*> *particle)
{
	particle->push_back(new Particle(v3(this->getPosition().x + rd(-500,500), this->getPosition().y, this->getPosition().z + rd(-500, 500)), v3(rd(10.0, 10.5), 3, rd(10.0, 10.5)), 10.0, 1.0, 200));
}