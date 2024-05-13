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
    float frc;
    float uniqueVal;
    float prevAngle;
    
    ofColor bg;
    ofColor line;
};
