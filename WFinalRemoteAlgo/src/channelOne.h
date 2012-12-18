//
//  channelOne.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/11/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__channelOne__
#define __remoteMusicVisualizer_junsikjasonkim__channelOne__

#include <iostream>
#include "ofMain.h"
#include "baseScene.h"
#include "particle.h"
#include "particletwo.h"
#include "xenoPointer.h"
#include "spring.h"


class channelOne : public baseScene {
    
    public:
        
        void setup();
        void update();
        void draw(float yaw, float pitch, float roll, int buttonState);
        
        //IMU data
        float channelOneYaw;
        float channelOnePitch;
        float channelOneRoll;
        int   channelOneButton;
        
        float imuSpeed;
        
        ofTrueTypeFont myFont;
        ofTrueTypeFont mySmallFont;
        //    ofImage leftMenu;
    
        //Remove noise of IMU using xenopointer
        xenoPointer xenopointerone;
    
        float myLineWidth;
    
    
        //Button
        float buttonValue;
        float lastButtonValue;
    
        ofColor myColor;
    
        //Spring Particles
        vector <particletwo> particles;
        vector <spring> springs;
        vector <ofPoint> trail;
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__channelOne__) */
