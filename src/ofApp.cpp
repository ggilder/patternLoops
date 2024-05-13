#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetBackgroundColor(235,230,211);
    ofSetBackgroundAuto(false);
    
    gui.setup();
    gui.add(trail.setup("trail", 4, 0, 100));

	p.assign(20, noodle());

	for (int i = 0; i < p.size(); i++) {
		p[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < p.size(); i++) {
		p[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(0, 0, 0, trail);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 0; i < p.size(); i++) {
		p[i].draw();
	}
    
//    gui.draw();

//    ofSetColor(250,225,200);
//    ofSetLineWidth(20);
//    ofDrawLine(685.4, 275.5, 693.8, 302.5);
//    ofDrawLine(693.8, 302.5, 703.3, 329.2);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
