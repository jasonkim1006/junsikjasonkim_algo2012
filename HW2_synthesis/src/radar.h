//
//  radar.h
//  HW2_synthesis
//
//  Created by Jun Sik (Jason) Kim on 9/25/12.
//
//

#ifndef __HW2_synthesis__radar__
#define __HW2_synthesis__radar__

#include "ofMain.h"


class radar{
public:
    
    void draw();
    void update();
    float angle;
    float width;
    float speed;
    
    bool inside(float ball_angle)
    {
        return ball_angle > angle - width && ball_angle < angle + width;
    }
};

#endif /* defined(__HW2_synthesis__radar__) */
