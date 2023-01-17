#include "Generator.h"
#include <random>

Generator::Generator(v3 posvec, int amount)
{
	this->setPosition(posvec);
	this->setAmount(amount);
	this->sphere.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->material.setDiffuseColor(ofFloatColor::darkGreen);

	this->sphere.setRadius(10);
	this->sphere.setResolution(2);
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

int Generator::getAmount()
{
	return amount;
}

void Generator::setAmount(int newAmount)
{
	this->amount = newAmount;
}

void Generator::generate(vector<Particle*>* particle)
{
	for (int i = 0; i < amount;i++)
	{
		particle->push_back(new Particle(v3(this->getPosition().x + random(-500, 500), this->getPosition().y, this->getPosition().z + random(-500, 500)), v3(random(10.0, 10.5), 3, random(10.0, 10.5)), 10.0, 1.0, 200));
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
