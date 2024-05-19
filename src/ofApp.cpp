#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    buffer.allocate(ofGetWindowWidth(), ofGetWindowHeight());

    ofSetFrameRate(60);
    ofSetBackgroundColor(235, 230, 211);

    gui.setup();

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
    buffer.begin();
    if (!bufferInitialized) {
        // On first frame, clear buffer
        ofClear(255, 255, 255, 0);
        bufferInitialized = true;
    }

    ofSetColor(ofGetBackgroundColor(), trail);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    for (int i = 0; i < p.size(); i++) {
        p[i].draw();
    }

    // No gui controls for now
    /* gui.draw(); */

    buffer.end();
    buffer.draw(0, 0);
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
