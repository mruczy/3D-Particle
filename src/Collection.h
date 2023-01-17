#ifndef COLLECTION_H
#define COLLECTION_H

#include "Emitter.h"
#include "Particle.h"
#include "ForcePoint.h"
#include "ForceWind.h"
#include "Object.h"
#include "Prezent.h"
#include "Choinka.h"
#include "Ognisko.h"



class Collection
{
public:

	std::vector<Emitter*> emitter;
	std::vector<Particle*> particle;
	std::vector<ForcePoint*> forcepoint;
	std::vector<ForceWind*> wind;
	std::vector<Object*> object;

	Collection();
	virtual ~Collection();

	void addEmitter(v3 posvec, string name);
	//void deleteEmitter();

	void addPoint(v3 posvec);
	//void deletePoint();

	void addWind(v3 posvec);
	//void deleteWind();

	void collectionUpdate();
	void particleUpdate();

	void draw();
};

#endif