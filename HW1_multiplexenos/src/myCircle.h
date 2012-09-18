//
//  myCircle.h
//  HW1_multiplexenos
//
//  Created by Jun Sik (Jason) Kim on 9/17/12.
//
//

#ifndef __HW1_multiplexenos__myCircle__
#define __HW1_multiplexenos__myCircle__

#pragma once

#include "ofMain.h"

class myCircle {
public:
    
    myCircle();
    
    void setup();
    void update();
    void draw();
    void xenoToPoint(float catchX, float catchY);
    
    float angle;
    float dist;
    float radius;
    float counter;
    ofColor color;
    
    float	catchUpSpeed;	
    ofPoint circlepos;
    
};


#endif 
