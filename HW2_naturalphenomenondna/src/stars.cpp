//
//  stars.cpp
//  HW2_naturalphenomenon
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#include "stars.h"


void stars::setup(){
    
}

void stars::update(){
    
    
}

void stars::draw(){
    circleradius = sin(ofGetElapsedTimef()*2.0);
    circleradiusmap = ofMap(circleradius, -1, 1, 5, 10);
    
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    angle = ofGetElapsedTimef()*0.5;
    radius = ofGetHeight()/3 + 50;
    
   	x = xorig + radius/2 * cos(angle * 6.4);
	y = yorig + radius * -sin(angle * 2.9);
    
//    x = xorig + radius * cos(angle * 3.0);
//	y = yorig + radius * -sin(angle * 3.0);
    
    
    temp.x = x;
    temp.y = y;
    
    starpoints.push_back(temp);
    if (starpoints.size() > 400){
        starpoints.erase(starpoints.begin());
    }

    ofNoFill();
    ofSetColor(255,255,255);
    ofBeginShape();
	for (int i = 0; i < starpoints.size(); i++){
		ofVertex(starpoints[i].x, starpoints[i].y);
        ofCircle(starpoints[i].x, starpoints[i].y, circleradiusmap);
	}
	ofEndShape();
    
    ofSetColor(255,255,0);
    ofFill();
    ofCircle(x,y,circleradiusmap);
    ofSetColor(255,215,0);
    ofCircle(x,y,5);
    
}