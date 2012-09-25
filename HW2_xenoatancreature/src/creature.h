//
//  creature.h
//  HW2_xenoatancreature
//
//  Created by Jun Sik (Jason) Kim on 9/24/12.
//
//

#ifndef __HW2_xenoatancreature__creature__
#define __HW2_xenoatancreature__creature__


#include "ofMain.h"

class creature {
    
public:
	
    creature();
	
    void	draw();
    void	xenoToPoint(float catchX, float catchY);
	
    ofPoint		pos;
    ofPoint		prevPos;
    
    float		angle;
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
    
    //creature legs
    int     joint;
    float   jointwave;
    float   jointwave2;
	

};

#endif /* defined(__HW2_xenoatancreature__creature__) */
