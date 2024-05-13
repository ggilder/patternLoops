#include "noodle.hpp"

noodle::noodle() {
}

void noodle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();

    vel.x = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 1);
    
    frc = 0;
    uniqueVal = ofRandom(-1000, 1000);
    
    bg = ofColor(235,230,211);
    line = ofColor(208,169,87);
    
    prevAngle = 999;
}

void noodle::update() {
    int overdraw = 10;
    frc = ofSignedNoise(uniqueVal, ofGetElapsedTimeMillis());

    frc = abs(frc) > 0.75 ? 5 + (1 - frc) : 0.1 * frc;

    vel.rotate(frc);

    //RESET AT BORDER
    if (pos.x + vel.x > ofGetWidth() + overdraw) {
        pos.x -= ofGetWidth();
    }
    else if (pos.x + vel.x < -overdraw) {
        pos.x += ofGetWidth();
    }

    if (pos.y + vel.y > ofGetHeight() + overdraw) {
        pos.y -= ofGetHeight();
    }
    else if (pos.y + vel.y < -overdraw) {
        pos.y += ofGetHeight();
    }

    pos += vel;
}

void noodle::draw() {
    float lineWidth = 2;
    float width = 30;
    int steps = 20;
    int numLines = 5;
    
    float angle = vel.angle(ofVec2f(1, 0));
    ofVec2f prevPos = pos - vel;
//    printf("pos: %.1f, %.1f\n", pos.x, pos.y);
//    printf("prevPos: %.1f, %.1f\n", prevPos.x, prevPos.y);
//    printf("angle: %.1f\n", angle);
//    printf("====\n");
    ofSetColor(bg);
//    for (int i = 0; i < steps; i++) {
//        ofVec2f p = prevPos + (vel * i/steps);
//        ofDrawCircle(p, width / 2);
//    }
    auto u = vel.getPerpendicular().normalize();
    
    ofSetColor(bg);
    for (int i = -width / 2; i <= width / 2; i++) {
        ofDrawCircle(pos + (u * i), lineWidth / 2);
    }
    
    ofSetColor(line);
    float spacing = width / (numLines - 1);
    for (int i = ceil(-numLines / 2); i <= floor(numLines / 2); i++) {
        ofDrawCircle(pos + (u * i * spacing), lineWidth / 2);
    }
    
    
    prevAngle = angle;
}
