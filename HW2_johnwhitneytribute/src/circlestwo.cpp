//
//  circlestwo.cpp
//  HW2_johnwhitneytribute
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#include "circlestwo.h"

void circlestwo::setup(){
    
}

void circlestwo::update(){
    
    
}

void circlestwo::draw(){
    
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    
    //    angle = ofGetElapsedTimef() * 8.0;
    
    x = xorig - radius * cos(angle);
    y = yorig - radius * -sin(angle);
    
//    circleradius = 5;
    
    ofSetColor(color.r,color.g,color.b);
    ofCircle(x, y, circleradius);
    //    ofCircle(x, y, radius);
    
}
