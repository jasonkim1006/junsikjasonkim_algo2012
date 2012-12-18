//
//  channelOne.cpp
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/11/12.
//
//

#include "channelOne.h"

//SCREENONE MAINMENU SCREEN

/*
 UP: clear trail
 DOWN: yawoffset
 LEFT: line width reduce
 RIGHT: line width increase
 CENTER: color + channel select
 */

//------------------------------------------------------------------
void channelOne::setup(){

    myFont.loadFont("Arial Bold.ttf", 10);
    mySmallFont.loadFont("Arial Bold.ttf", 8);
//    leftMenu.loadImage("images/test.png");
    
    imuSpeed = 20;
    xenopointerone.catchUpSpeed = 0.1f;
    xenopointerone.xenoRadius = 3;
    
    myLineWidth = 1;
    
    //Spring Particle
    for (int i = 0; i < 5; i++){
		particletwo myParticle;
		myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
		particles.push_back(myParticle);
	}
	
	for (int i = 0; i < (particles.size()-1); i++){
		spring mySpring;
		mySpring.distance		= 25;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
}

//------------------------------------------------------------------
void channelOne::update(){
    
    ofBackground(15,15,15);
    
    //Spring Particle
    for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	for (int i = 0; i < particles.size(); i++){
		//particles[i].addForce(0,0.1);
	}
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
        particles[i].bounceOffWalls();
	}
    
    //Line trace
    trail.push_back(particles[0].pos);
    trail.push_back(particles[4].pos);
    if (trail.size() > 2){
        trail.erase(trail.begin());
    }
    if (channelOneButton == 1){
        trail.clear();
    }

    //Line width for drawing tool
    if(channelOneButton == 4){
        myLineWidth += 1;
    }
    if(channelOneButton == 3){
        myLineWidth -= 1;
        if(myLineWidth <= 1){
            myLineWidth = 1;
        }
    }

    xenopointerone.xenoToPoint(channelOneYaw, channelOnePitch);
}

//------------------------------------------------------------------
void channelOne::draw(float yaw, float pitch, float roll, int buttonState){
    
    ofSetColor(200,200,200);
    myFont.drawString("IMRemote Algorithmic Animation", ofGetWidth()/2 - 90, 50);
    myFont.drawString("Jun Sik (Jason) Kim", ofGetWidth()/2 - 50, 70);
    
    channelOneYaw   = yaw;
    channelOnePitch = pitch;
    channelOneRoll  = roll;
    channelOneButton = buttonState;
    
    //Spring Particle
    for (int i = 0; i < particles.size(); i++){
//		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
//		springs[i].draw();
	}
	ofNoFill();
	ofBeginShape();
//    ofSetColor(20,150,20,20);
    ofSetColor(myColor,17);
    ofSetLineWidth(myLineWidth);
	for (int i = 0; i < trail.size(); i++){
		ofVertex(trail[i].x, trail[i].y);
	}
	ofEndShape();
    ofSetLineWidth(1);
    ofFill();
    
    
    
    if(channelOneButton == 5){
        particles[0].pos.set(xenopointerone.pos.x, xenopointerone.pos.y);
        particles[0].bFixed = true;
    }
    else{
        particles[0].bFixed = false;
    }
    
    //Button Counter
    buttonValue = channelOneButton;
    
    if(buttonValue != lastButtonValue){
        if(buttonValue == 5){
            myColor.r = ofRandom(0,255);
            myColor.g = 150;
            myColor.b = 20;
        }
        lastButtonValue = buttonValue;
    }
    
    //Boundaries for xenopointer (Sketch Canvas)
    if (channelOneYaw >= ofGetWidth() - xenopointerone.xenoRadius){
        channelOneYaw = ofGetWidth() - xenopointerone.xenoRadius;
    }
    if (channelOneYaw <= 0 + xenopointerone.xenoRadius){
        channelOneYaw = 0 + xenopointerone.xenoRadius;
    }
    
    //Channel Menus
    if (channelOnePitch >= ofGetHeight() - xenopointerone.xenoRadius){
        channelOnePitch = ofGetHeight() - xenopointerone.xenoRadius;
        ofSetColor(200,200,200,30);
        ofRectMode(OF_RECTMODE_CENTER);
        ofRect(ofGetWidth()/2-270, ofGetHeight() - 35, 200, 70);
        ofRect(ofGetWidth()/2+270, ofGetHeight() - 35, 200, 70);
        ofSetColor(200,200,200,150);
        myFont.drawString("Channel 1", ofGetWidth()/2 - 300, ofGetHeight() - 70);
        myFont.drawString("Channel 2", ofGetWidth()/2 + 240, ofGetHeight() - 70);
        
        if(channelOneYaw >= ofGetWidth()/2 - 370 && channelOneYaw <= ofGetWidth()/2 - 170){
            ofSetColor(190, 0, 65);
            ofRect(ofGetWidth()/2-270, ofGetHeight() - 35, 200, 70);
            myFont.drawString("Channel 1", ofGetWidth()/2 - 300, ofGetHeight() - 70);
            if(channelOneButton == 5){
            }
        }
        if(channelOneYaw >= ofGetWidth()/2 + 170 && channelOneYaw <= ofGetWidth()/2 + 370){
            ofSetColor(20, 140, 200);
            ofRect(ofGetWidth()/2+270, ofGetHeight() - 35, 200, 70);
            myFont.drawString("Channel 2", ofGetWidth()/2 + 240, ofGetHeight() - 70);
            if(channelOneButton == 5){
            }
        }
    }
    if (channelOnePitch <= 0 + xenopointerone.xenoRadius){
        channelOnePitch = 0 + xenopointerone.xenoRadius;
    }
    
    ofSetColor(255,255,100);
    xenopointerone.draw();
    

}




