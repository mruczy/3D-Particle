#include "ofApp.h"
#include <cmath>
#include <random>
#include "Collection.h"

//--------------------------------------------------------------
void ofApp::setup() {

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
		colle->collisionUpdate();
		colle->particleUpdate();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	cam.begin();
	ofEnableLighting();

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

