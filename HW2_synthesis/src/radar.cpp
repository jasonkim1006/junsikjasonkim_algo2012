//
//  radar.cpp
//  HW2_synthesis
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#include "radar.h"


void radar::update(){
    angle += speed;
    if(angle < 0)
        angle += 360;
    if(angle > 360)
        angle -= 360;
}

void radar::draw(){
    ofSetColor(255,255,0);
    //length of radar
    float x1 = 2000 * cos(ofDegToRad(angle + width));
    float y1 = 2000 * sin(ofDegToRad(angle + width));
    
    float x2 = 2000 * cos(ofDegToRad(angle - width));
    float y2 = 2000 * sin(ofDegToRad(angle - width));
    
    ofTriangle(ofGetWidth()/2,ofGetHeight()/2,x1,y1,x2,y2);
}