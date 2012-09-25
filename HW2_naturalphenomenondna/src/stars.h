//
//  stars.h
//  HW2_naturalphenomenon
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#ifndef __HW2_naturalphenomenon__stars__
#define __HW2_naturalphenomenon__stars__

#include "ofMain.h"

class stars {
public:
    
    void setup();
    void update();
    void draw();
    
    float angle;
    float dist;
    float radius;
    float circleradius;
    float circleradiusmap;
    
    float xorig;
    float yorig;
    
    float x;
    float y;
    
    ofColor color;
    ofPoint temp;
    
    vector < ofPoint > starpoints;
    
};

#endif /* defined(__HW2_naturalphenomenon__stars__) */
