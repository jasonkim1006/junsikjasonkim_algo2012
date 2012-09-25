//
//  circles.cpp
//  HW2_johnwhitneytribute
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#include "circles.h"


void circles::setup(){

}

void circles::update(){
    

}

void circles::draw(){
    
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    
//    angle = ofGetElapsedTimef() * 8.0;

    x = xorig + radius * cos(angle);
    y = yorig + radius * -sin(angle);
    
//    circleradius = 5;
    
    ofSetColor(color.r,color.g,color.b);
    ofCircle(x, y, circleradius);
//    ofCircle(x, y, radius);
    
}

void circles::drawLine(){
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    
    x = xorig + radius * cos(angle);
    y = yorig + radius * -sin(angle);
    
//    for(int i = 0; i<10; i++){
//        float x0 = xorig + cos(ofDegToRad((360/10.0) * i));
//        float y0 = yorig + sin(ofDegToRad((360/10.0) * i));
//        ofLine(x0, y0, x, y);
//    }
    
    float lineradius = sin(ofGetElapsedTimef());
    float lineradiusmapped = ofMap(lineradius, -1, 1, -10, 10);
    
    
    float x0 = xorig + cos(angle)*40.0*lineradiusmapped;
    float y0 = yorig + -sin(angle)*40.0*lineradiusmapped;
    ofLine(x0, y0, x, y);
    
    
//    float x = dist * cos(ofDegToRad(angle));
//    float y = dist * sin(ofDegToRad(angle));
//    
//    for(int i = 0; i<10; i++){
//        float x0 = 75 * cos(ofDegToRad((360/10.0) * i));
//        float y0 = 75 * sin(ofDegToRad((360/10.0) * i));
//        ofLine(x0, y0, x, y);
//    }
}