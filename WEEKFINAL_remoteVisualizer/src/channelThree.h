//
//  channelThree.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/17/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__channelThree__
#define __remoteMusicVisualizer_junsikjasonkim__channelThree__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"
#include "xenoPointer.h"
#include "particle.h"

class channelThree : public baseScene {
    
    public:
        
        void setup();
        void update();
        void draw(float yaw, float pitch, float roll, int buttonState);
    
        float channelThreeYaw;
        float channelThreePitch;
        float channelThreeRoll;
        int   channelThreeButton;
    
        ofTrueTypeFont myFont;
        xenoPointer xenopointerthree;
        ofSoundPlayer mySong;
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__channelThree__) */
