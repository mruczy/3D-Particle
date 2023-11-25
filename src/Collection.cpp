#include "Collection.h"
#include <math.h>

Collection::Collection()
{
	//Emitter snow
	this->addEmitter(v3(50, 500, 0), "snow");

	//Emitter smoke
	this->addEmitter(v3(0, 0, 0), "smoke");

	this->addPoint(v3(500, 50, 50), 0.5);
	this->addWind(v3(0, 0, 200), v3(1, 0.1, -1), 1);

	for (auto* emit : this->emitter)
	{
		if (emit->getName() == "snow")
		{
			emit->addGenerator(emit->getPosition(), v3(0, -10, 0), 9.81, 20, 2, 1, 200, 1, ofColor::white);
		}

		if (emit->getName() == "smoke")
		{
			emit->addGenerator(emit->getPosition(), v3(0, 5, 0), 0.0, 2, 1, 1, 100, 1, ofColor::orange);
		}
	}

	for (auto d = 0; d <= 180; d += 30)
	{
		float x = 300 * cos(d * (PI / 180));
		float z = 300 * sin(d * (PI / 180));
		this->addObject(v3(x, 60, z), 1);

		for (auto d = 0; d <= 360; d += 72)
		{
			float x2 = 40 * cos(d * (PI / 180)) + x;
			float z2 = 40 * sin(d * (PI / 180)) + z;
			this->addObject(v3(x2, 10, z2), 2);
		}
	}

	this->addObject(v3(0, 20, 0), 3);
	this->addObject(v3(0, 0, 0), 4);
}


Collection::~Collection()
{
}

void Collection::addEmitter(v3 posvec, string name)
{
	this->emitter.push_back(new Emitter(posvec, name));
}

void Collection::addPoint(v3 posvec, float force)
{
	this->forcepoint.push_back(new ForcePoint(posvec, force));
}

void Collection::addWind(v3 posvec, v3 fvec, float force)
{
	this->wind.push_back(new ForceWind(posvec, fvec, force));
}

void Collection::addObject(v3 posvec, int value)
{
	switch (value)
	{
	case 1:
		this->object.push_back(new Choinka(posvec));
		break;
	case 2:
		this->object.push_back(new Prezent(posvec));
		break;
	case 3:
		this->object.push_back(new Ognisko(posvec));
		break;
	case 4:
		this->object.push_back(new Plane(posvec));
		break;
	default:
		break;
	}
}

void Collection::collectionUpdate()
{
	for (auto* emit : this->emitter)
	{
		if (emit->getName() == "snow")
		{
			for (auto* gen : emit->getGenerator())
			{
				gen->generate(&particle, 500);
			}
		}

		if (emit->getName() == "smoke")
		{
			for (auto* gen : emit->getGenerator())
			{
				gen->generate(&particle, 20);
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

void Collection::collisionUpdate()
{
	for (auto* part : this->particle)
	{
		for (auto* obj : this->object)
		{
			if (obj->getIsCollision() == true)
			{
				if (part->getPosition().y < obj->getPosition().y)
				{
					part->setVelocity(v3(part->getVelocity().x, -part->getVelocity().y/5, part->getVelocity().z));
				}
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


