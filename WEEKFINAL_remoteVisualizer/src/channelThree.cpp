//
//  channelThree.cpp
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/17/12.
//
//

#include "channelThree.h"

//SCREENTHREE AUDIOVISUALIZER
//------------------------------------------------------------------
void channelThree::setup(){
    
    myFont.loadFont("Arial Bold.ttf", 10);
    
    xenopointerthree.catchUpSpeed = 0.1f;
    xenopointerthree.xenoRadius = 3;
}

//------------------------------------------------------------------
void channelThree::update(){
    ofBackground(15,15,15);
    xenopointerthree.xenoToPoint(channelThreeYaw, channelThreePitch);
}

//------------------------------------------------------------------
void channelThree::draw(float yaw, float pitch, float roll, int buttonState){
    
    ofSetColor(200,200,200);
    myFont.drawString("Channel 2", ofGetWidth()/2 - 30, 50);
    
    channelThreeYaw   = yaw;
    channelThreePitch = pitch;
    channelThreeRoll  = roll;
    channelThreeButton = buttonState;
    
    if (channelThreeYaw > ofGetWidth() - xenopointerthree.xenoRadius){
        channelThreeYaw = ofGetWidth() - xenopointerthree.xenoRadius;
    }
    if (channelThreeYaw < 0 + xenopointerthree.xenoRadius){
        channelThreeYaw = 0 + xenopointerthree.xenoRadius;
    }
    if (channelThreePitch > ofGetHeight() - xenopointerthree.xenoRadius){
        channelThreePitch = ofGetHeight() - xenopointerthree.xenoRadius;
    }
    if (channelThreePitch < 0 + xenopointerthree.xenoRadius){
        channelThreePitch = 0 + xenopointerthree.xenoRadius;
    }
    
    xenopointerthree.draw();
    

}
