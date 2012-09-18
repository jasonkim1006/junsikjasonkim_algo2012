

#ifndef __HW1_multiplexenos__rectangle__
#define __HW1_multiplexenos__rectangle__

#include "ofMain.h"

class rectangle {
    
public:
	
    rectangle();
	
    void	draw();
    void	xenoToPoint(float catchX, float catchY);
	
    ofPoint		pos;
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    
};

#endif /* defined(__HW1_multiplexenos__rectangle__) */
