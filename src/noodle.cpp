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

    ofVec2f prevPos = pos - vel;

    auto prevPerp = prevVel.getPerpendicular().normalize();
    auto perp = vel.getPerpendicular().normalize();

    ofSetColor(bg);
    ofBeginShape();
    ofVertex(prevPos + prevPerp * width / 2);
    ofVertex(prevPos - prevPerp * width / 2);
    ofVertex(pos - perp * width / 2);
    ofVertex(pos + perp * width / 2);
    ofEndShape(true);

    ofSetColor(line);
    ofSetLineWidth(lineWidth);
    float spacing = width / (numLines - 1);
    for (int i = ceil(-numLines / 2); i <= floor(numLines / 2); i++) {
        ofDrawLine(prevPos + (prevPerp * i * spacing), pos + (perp * i * spacing));
    }

    prevVel = vel;
}
