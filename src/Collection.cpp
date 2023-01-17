#include "Collection.h"
#include <random>

Collection::Collection()
{
	this->addEmitter(v3(50, 500, 0));
	this->addPoint(v3(500, 20, 50));
	this->addWind(v3(500, 20, 50));

	for (int x = -500; x <= 500; x += 100) {
		for (int z = -500; z <= 0; z += 100) {
			this->object.push_back(new Choinka(v3(x, -60, z)));
		}
	}

	for (int x = -300; x <= 300; x += 60) {
		for (int z = 0; z <= 300; z += 60) {
			this->object.push_back(new Prezent(v3(x + 20, -80, z - 10)));
		}
	}
}


Collection::~Collection()
{
}

void Collection::addEmitter(v3 posvec)
{
	this->emitter.push_back(new Emitter(posvec));
}

void Collection::addPoint(v3 posvec)
{
	this->forcepoint.push_back(new ForcePoint(v3(500, 0, 0), 5));
}

void Collection::addWind(v3 posvec)
{
	this->wind.push_back(new ForceWind(v3(0, 0, 200), v3(300, 15, -10), 600));
}

void Collection::collectionUpdate()
{
	for (auto* emit : this->emitter)
	{
		{
			for (int i = 0; i < 10; i++)
			{
				if (this->particle.size() < 1000) {
					emit->generate(&particle);
				}
			}
		}
	}

	float fx;
	float fy;
	float fz;
	for (auto* point : this->forcepoint)
	{
		for (auto* part : this->particle)
		{
			((part->getPosition().x - point->getPosition().x > 0.0) ? fx = 1 : fx = -1);
			((part->getPosition().y - point->getPosition().y > 0.0) ? fy = 1 : fy = -1);
			((part->getPosition().z - point->getPosition().z > 0.0) ? fz = 1 : fz = -1);
			part->addForce(v3(fx * point->getForce(), fy * point->getForce(), fz * point->getForce()));
		}
	}

	float dist;
	for (auto* w : this->wind)
	{
		for (auto* part : this->particle)
		{
			dist = sqrt(pow(part->getPosition().x - w->getPosition().x, 2) * pow(part->getPosition().y - w->getPosition().y, 2));
			if (dist < w->getRadius())
			{
				part->addForce(v3(w->getForce().x, w->getForce().y, w->getForce().z));
			}
		}
	}
}

void Collection::particleUpdate()
{
	unsigned counter = 0;
	for (auto* part : this->particle)
	{
		part->updateParticle(0.1);
		if (part->getLife() == part->getMaxLife())
		{
			delete this->particle.at(counter);
			this->particle.erase(this->particle.begin() + counter);
		}

		if (part->getPosition().y <= -120)
		{
			delete this->particle.at(counter);
			this->particle.erase(this->particle.begin() + counter);
		}
		++counter;
	}
}

void Collection::draw()
{
	for (auto* emit : this->emitter)
	{
		emit->draw();
	}

	for (auto* part : this->particle)
	{
		part->draw();
	}

	for (auto* point : this->forcepoint)
	{
		point->draw();
	}

	for (auto* w : this->wind)
	{
		w->draw();
	}

	for (auto* obj : this->object)
	{
		obj->draw();
	}
}


