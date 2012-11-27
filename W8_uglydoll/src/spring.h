//
//  spring.h
//  W8_creaaature
//
//  Created by Jun Sik (Jason) Kim on 11/23/12.
//
//

#ifndef __W8_creaaature__spring__
#define __W8_creaaature__spring__

#include "ofMain.h"
#include "particle.h"

class spring {
    
public:
    
    spring();
    
    particle * particleA;
    particle * particleB;
    
    float restLength;
    float distance;
    float springiness;	 // this is the k, springiness constant
	
    void update();
    void draw();
	
	
};

#endif /* defined(__W8_creaaature__spring__) */
