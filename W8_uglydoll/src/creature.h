//
//  creature.h
//  W8_creaaature
//
//  Created by Jun Sik (Jason) Kim on 11/26/12.
//
//

#ifndef __W8_creaaature__creature__
#define __W8_creaaature__creature__

#include <iostream>
#include "ofMain.h"
#include "particle.h"
#include "spring.h"

#endif /* defined(__W8_creaaature__creature__) */

class creature {
    public:
        void setup(ofColor color, float size);
        void update();
        void draw();
        void creatureSpring(particle * p1, particle * p2);
        void moveMouse(float x, float y);
        ofPoint pos;
        ofColor color;
        float size;
        float sinDiff;
        float mouseX, mouseY;
    
        vector <particle *> particles;
        vector <spring> springs;
    
};