//
//  baseScene.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/11/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__baseScene__
#define __remoteMusicVisualizer_junsikjasonkim__baseScene__

#include <iostream>
#include "ofMain.h"

class baseScene {
public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(float yaw, float pitch, float roll, int buttonState){}

    
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__baseScene__) */
