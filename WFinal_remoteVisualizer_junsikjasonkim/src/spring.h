//
//  spring.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/18/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__spring__
#define __remoteMusicVisualizer_junsikjasonkim__spring__

#include <iostream>
#include "particletwo.h"


class spring {
    
public:
    
    spring();
    
    particletwo * particleA;
    particletwo * particleB;
    
    float distance;
    float springiness;	 // this is the k, springiness constant
	
    void update();
    void draw();
		
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__spring__) */
