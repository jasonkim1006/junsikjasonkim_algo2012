//
//  circles.h
//  HW1_multiplexenos
//
//  Created by Jun Sik (Jason) Kim on 9/18/12.
//
//


#ifndef __HW1_multiplexenos__circles__
#define __HW1_multiplexenos__circles__

#include "ofMain.h"

class circles {
    
public:
	
    circles();
	
    void	draw();
    void	xenoToPoint(float catchX, float catchY);
	
    ofPoint		circlepos;
    float		circlecatchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    
};


#endif 