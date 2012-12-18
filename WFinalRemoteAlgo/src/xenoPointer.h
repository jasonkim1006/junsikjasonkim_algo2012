//
//  xenoPointer.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/10/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__xenoPointer__
#define __remoteMusicVisualizer_junsikjasonkim__xenoPointer__

#include <iostream>
#include "ofMain.h"

class xenoPointer {
    
    public:
    
    xenoPointer();
//    void    draw(float roll);
    void    draw();
    void    xenoToPoint(float catchX, float catchY);
    ofPoint pos;
    float   catchUpSpeed;
    float   xenoRadius;
    
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__xenoPointer__) */
