//
//  mycircle.h
//  HW1_shaper
//
//  Created by Jun Sik (Jason) Kim on 9/17/12.
//
//

#ifndef __HW1_shaper__mycircle__
#define __HW1_shaper__mycircle__

#include "ofMain.h"

class mycircle {
    
public:
	
    mycircle();
	
    void draw();
    void interpolateByPct(float myCirclePct);
    
    ofPoint		circlepos;
    ofPoint		circleposa;
    ofPoint		circleposb;
    float		circlepct;	// what pct are we between "a" and "b"
    float		circleshaper;
	float       circleradius;
    
    ofColor     circlecolor;
    
	
    
};

#endif /* defined(__HW1_shaper__mycircle__) */
