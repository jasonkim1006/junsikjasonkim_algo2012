//
//  myCircle.cpp
//  HW1_multiplexenos
//
//  Created by Jun Sik (Jason) Kim on 9/17/12.
//
//

#include "myCircle.h"

myCircle:: myCircle(){
	catchUpSpeed = 0.03f;
}

void myCircle::setup(){
    color.r = 50;
    color.g = 150;
    color.b = 255;
    color.a = 255;
    circlepos.x = dist * cos(ofDegToRad(angle));
    circlepos.y = dist * sin(ofDegToRad(angle));
}

void myCircle::update(){
    
    
    
    
    
    
    angle += -1;
    //no negative numbers
    if(angle < 0)
        angle += 360;
    //361 becomes 1
    if(angle > 360)
        angle -= 360;
}

void myCircle::draw(){
    ofSetColor(color.r, color.g, color.b, color.a);
    
    //ofDegToRad returns the converted value of a degrees angle in radians. (degrees = 90 -> we obtain Pi/2)
    //converting from polar Coordinates (r, S) to cartesian coordinates (x,y)
    //X = R*cos(Theta)
    //y = R*sin(Theta)
    
    circlepos.x = dist * cos(ofDegToRad(angle));
    circlepos.y = dist * sin(ofDegToRad(angle));
    
    ofCircle(circlepos.x, circlepos.y, radius);
    
}

void myCircle::xenoToPoint(float catchX, float catchY){
	circlepos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * circlepos.x;
	circlepos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * circlepos.y;
}
