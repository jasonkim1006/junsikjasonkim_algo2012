//
//  channelTwo.cpp
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/11/12.
//
//

#include "channelTwo.h"

//SCREENTWO PARTICLE SCREEN

/*
 
 UP: back to menu screen
 CENTER: attract
 ROLL: determins clockwise, counterclockwise
 PITCH: y axis of particles
 
 */
//------------------------------------------------------------------
void channelTwo::setup(){
    
    myFont.loadFont("Arial Bold.ttf", 10);
    
    for(int i = 0; i < 5000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0, 0);
        particlestwo.push_back(myParticle);
    }
    isRepulsive = false;
    
    imuSpeed = 20;
    
    xenopointertwo.catchUpSpeed = 0.1f;
    xenopointertwo.xenoRadius = 5;
    
    
}

//------------------------------------------------------------------
void channelTwo::update(){
    ofBackground(15,15,15);
    
    for (int i = 0; i < particlestwo.size(); i++){
        particlestwo[i].resetForce();
        particlestwo[i].bounceOffWalls();
        channelTwoRollMapClockwise = ofMap(channelTwoRoll, -30, -100, 0.0, 3.0);
        channelTwoRollMapCounter = ofMap(channelTwoRoll, 30, 100, 0.0, 3.0);
        channelTwoRollMapForceClockwise = ofMap(channelTwoRoll, -30, -100, 0.0, 1000.0);
        channelTwoRollMapForceCounter = ofMap(channelTwoRoll, 30, 100, 0.0, 1000.0);
        
        if(channelTwoButton == 5){
            particlestwo[i].addAttractionForce(channelTwoYaw, channelTwoPitch, 2000, 1.0);
        }
        
        if(channelTwoRoll > 30){
            particlestwo[i].addCounterClockwiseForce(channelTwoYaw, channelTwoPitch, channelTwoRollMapForceCounter, channelTwoRollMapCounter);
            if(channelTwoButton == 5){
            }
        }
        if(channelTwoRoll < -30){
            particlestwo[i].addClockwiseForce(channelTwoYaw, channelTwoPitch, channelTwoRollMapForceClockwise, channelTwoRollMapClockwise);
        }
        
        if(isRepulsive == false){
            particlestwo[i].addRepulsionForce(channelTwoYaw, channelTwoPitch, 200, 0.4);
        }
        
        else if(isRepulsive == true){
            particlestwo[i].addAttractionForce(channelTwoYaw, channelTwoPitch, 1000, 0.3);
        }
		
        if(particlestwo[i].pos.x < ofGetWidth()/2){
            particlestwo[i].addForce(0.04,0);
        }
        else if(particlestwo[i].pos.x > ofGetWidth()/2){
            particlestwo[i].addForce(-0.04,0);
        }
        
        if(particlestwo[i].pos.y < ofGetHeight()/2){
            particlestwo[i].addForce(0,0.04);
        }
        else if(particlestwo[i].pos.y > ofGetHeight()/2){
            particlestwo[i].addForce(0,-0.04);
        }
        
//		particlestwo[i].addForce(0,0.04);  // gravity
		particlestwo[i].addDampingForce();
		particlestwo[i].update();
    }
    
    buttonValue = channelTwoButton;
    
    if(buttonValue != lastButtonValue){
        if(buttonValue == 3){
            for(int i = 0; i < particlestwo.size(); i++){
                particlestwo[i].setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0, 0);
            }
        }
        lastButtonValue = buttonValue;
    }
    
    
    
    xenopointertwo.xenoToPoint(channelTwoYaw, channelTwoPitch);
}

//------------------------------------------------------------------
void channelTwo::draw(float yaw, float pitch, float roll, int buttonState){
    
    ofSetColor(200,200,200);
    myFont.drawString("Channel 1", ofGetWidth()/2 - 30, 50);
    
//    channelTwoYaw   = yaw;
    channelTwoYaw   = ofGetWidth()/2;
    channelTwoPitch = pitch;
    channelTwoRoll  = roll;
    channelTwoButton = buttonState;
    
    if(channelTwoButton == 1.0){
        //draw menu
    }

    if (channelTwoYaw > ofGetWidth() - xenopointertwo.xenoRadius){
        channelTwoYaw = ofGetWidth() - xenopointertwo.xenoRadius;
    }
    if (channelTwoYaw < 0 + xenopointertwo.xenoRadius){
        channelTwoYaw = 0 + xenopointertwo.xenoRadius;
    }
    if (channelTwoPitch > ofGetHeight() - xenopointertwo.xenoRadius){
        channelTwoPitch = ofGetHeight() - xenopointertwo.xenoRadius;
    }
    if (channelTwoPitch < 0 + xenopointertwo.xenoRadius){
        channelTwoPitch = 0 + xenopointertwo.xenoRadius;
    }
    
    for (int i = 0; i < particlestwo.size(); i++){
        particlestwo[i].draw();
    }
    if(channelTwoButton == 5){
//        isRepulsive = !isRepulsive;
    }
    
    if(channelTwoButton == 3){
        ofSetColor(255,255,100);
    }
    else if(channelTwoButton == 4){
        ofSetColor(200,200,200);
    }
        
    xenopointertwo.draw();

}