//
//  circles.h
//  HW2_johnwhitneytribute
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#ifndef __HW2_johnwhitneytribute__circles__
#define __HW2_johnwhitneytribute__circles__

#include "ofMain.h"

class circles {
public:
    
    void setup();
    void update();
    void draw();
    
    void drawLine();
    float angle;
    float dist;
    float radius;
    float circleradius;
    
    float xorig;
    float yorig;
    
    float x;
    float y;
    
    ofColor color; 
    
};


#endif /* defined(__HW2_johnwhitneytribute__circles__) */
