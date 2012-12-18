//
//  channelTwo.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/11/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__channelTwo__
#define __remoteMusicVisualizer_junsikjasonkim__channelTwo__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"
#include "xenoPointer.h"
#include "particle.h"


class channelTwo : public baseScene {
    
    public:
        
        void setup();
        void update();
        void draw(float yaw, float pitch, float roll, int buttonState);
        
        
        //Particles
        vector <particle> particlestwo;
        bool    isRepulsive;
        int     forceType;
        
        ofTrueTypeFont myFont;
        
        //IMU data
        float channelTwoYaw;
        float channelTwoPitch;
        float channelTwoRoll;
        float channelTwoRollMapClockwise;
        float channelTwoRollMapCounter;
        
        float channelTwoRollMapForceClockwise;
        float channelTwoRollMapForceCounter;
        
        int   channelTwoButton;
        
        float imuSpeed;
        
        //Remove noise of IMU using xenopointer
        xenoPointer xenopointertwo;
    
        //Button
        float buttonValue;
        float lastButtonValue;
    
};


#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__channelTwo__) */
