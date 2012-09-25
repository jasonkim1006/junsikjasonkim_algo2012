//
//  creature.cpp
//  HW2_xenoatancreature
//
//  Created by Jun Sik (Jason) Kim on 9/24/12.
//
//

#include "creature.h"

//------------------------------------------------------------------
creature::creature(){
	catchUpSpeed = 0.03f;
	
	pos.set(0,0);
	prevPos.set(0,0);
    
    joint = 30;
}

//------------------------------------------------------------------
void creature::draw() {
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); 
    ofSetColor(198,246,55);
    
    ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        ofRotateZ(angle * RAD_TO_DEG);
        for (int i = 0; i < joint; i++){
            jointwave = 20*sin(ofGetElapsedTimef()*4.0+i/10.0);
            ofSetColor(255-i*10, 255-i*10, 255-i*10, 255-i*8);
            ofCircle(pos.x/6.0+5*i+jointwave, pos.y/6.0+5*i-jointwave, 20-i*.5);
            ofCircle(jointwave, jointwave, 20-i*.5);
            
            ofPushMatrix();
                ofRotateZ(-(angle * RAD_TO_DEG));
                ofCircle(pos.x/10.0+10*i+jointwave, pos.y/10.0+10*i-jointwave, 20-i*.5);
            ofPopMatrix();
        }
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        ofRotateZ(-(angle * RAD_TO_DEG));
        for (int i = 0; i < joint; i++){
            ofSetColor(255-i*10,255-i*10,255-i*10,255-i*8);
            jointwave = 20*sin(ofGetElapsedTimef()*4.0+i/10.0);
            ofCircle(pos.x/6.0+5*i+jointwave, pos.y/6.0+5*i-jointwave, 20-i*.5);
        }
    ofPopMatrix();
    
    
    
    
	
	
}

//------------------------------------------------------------------
void creature::xenoToPoint(float catchX, float catchY){
	
	//JASON 1) SET POSITION
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
    //JASON 2) DO ACTION
    //JASON measuring the angle using the positions.
    //JASON dx = difference in x, dy = difference in y
	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
    //JASON calculating the angle between the two points. arctan
	angle = atan2(dy, dx);
    
    //JASON 3) SAVE POINT
	prevPos.x = pos.x;
	prevPos.y = pos.y;
	
    
}