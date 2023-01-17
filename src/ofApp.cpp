#include "ofApp.h"
#include <cmath>
#include <random>
#include "Collection.h"

//float rd(float min, float max)
//{
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> distr(min, max);
//	return distr(gen);
//}

//--------------------------------------------------------------
void ofApp::setup() {

	plane.set(1000, 1000);
	plane.rotateDeg(270, 1, 0, 0);
	plane.move(0, -100, 0);
	planeMaterial.setDiffuseColor(ofFloatColor::darkGreen);

	this->collection.push_back(new Collection());

	ofEnableLighting();
	ofEnableDepthTest();
	light.setup();
	light.enable();
	light.setPosition(-200, 200, 200);

	ofSetSphereResolution(1);
}

//--------------------------------------------------------------
void ofApp::update() {

	for (auto* colle : this->collection)
	{
		colle->collectionUpdate();
		colle->particleUpdate();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	cam.begin();
	ofEnableLighting();
	planeMaterial.begin();
	plane.draw();
	planeMaterial.end();

	ofDrawGrid(50, 1, true, true, true, true);

	for (auto* colle : this->collection)
	{
		colle->draw();
	}
	ofDisableLighting();
	cam.end();

	if (true)
	{
		stringstream ss;
		ss << "FPS: " << ofToString(ofGetFrameRate(), 0) << endl << endl;
		ss << "MODE: " << (cam.getOrtho() ? "ORTHO" : "PERSPECTIVE") << endl;
		ss << "ROTATION RELATIVE Y AXIS: " << (cam.getRelativeYAxis() ? "TRUE" : "FALSE") << endl;
		ofDrawBitmapString(ss.str().c_str(), 20, 150);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key)
	{
	case ' ':
		cam.getOrtho() ? cam.disableOrtho() : cam.enableOrtho();
		break;
	case 'y':
	case 'Y':
		cam.setRelativeYAxis(!cam.getRelativeYAxis());
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}


//void ofApp::updateForcePoints(float dt)
//{
//	for (auto* particle : this->particles)
//	{
//		for (auto* point : this->points)
//		{
//			float dist = sqrt(pow(particle->getPosition().x - point->getPosition().x, 2) * pow(particle->getPosition().y - point->getPosition().y, 2));
//			float fx = particle->getForce().x + pointMassMultiplier * 0.1 * point->getMass() * (particle->getPosition().x - point->getPosition().x) / pow(dist, 3.0);
//			float fy = particle->getForce().y + pointMassMultiplier * 0.1 * point->getMass() * (particle->getPosition().y - point->getPosition().y) / pow(dist, 3.0);
//			float fz = particle->getForce().z + pointMassMultiplier * 0.1 * point->getMass() * (particle->getPosition().z - point->getPosition().z) / pow(dist, 3.0);
//			particle->setForce(v3(fx, fy, fz));
//		}
//	}
//}
//
//void ofApp::updateForceParticles(float dt)
//{
//	float dist;
//	for (auto* particlei : this->particles)
//	{
//		for (auto* particlej : this->particles)
//		{
//			if (particlei != particlej)
//			{
//				float dist = sqrt(pow(particlei->getPosition().x - particlej->getPosition().x, 2) * pow(particlei->getPosition().y - particlej->getPosition().y, 2));
//				float fx = particlei->getForce().x + particleMassMultiplier * 0.1 * particlej->getMass() * (particlei->getPosition().x - particlej->getPosition().x) / pow(dist, 3.0);
//				float fy = particlei->getForce().y + particleMassMultiplier * 0.1 * particlej->getMass() * (particlei->getPosition().y - particlej->getPosition().y) / pow(dist, 3.0);
//				float fz = particlei->getForce().z + particleMassMultiplier * 0.1 * particlej->getMass() * (particlei->getPosition().z - particlej->getPosition().z) / pow(dist, 3.0);
//				particlei->setForce(v3(fx, fy, fz));
//			}
//		}
//	}
//}

