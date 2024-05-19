#pragma once

#include "ofMain.h"

class noodle {

public:
    noodle();

    void setup();
    void update();
    void draw();

    ofVec2f pos;
    ofVec2f vel;
    ofVec2f prevVel;
    float frc;
    float uniqueVal;

    ofColor bg;
    ofColor line;
};
