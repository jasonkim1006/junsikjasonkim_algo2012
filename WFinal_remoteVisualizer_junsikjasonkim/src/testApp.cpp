#include "testApp.h"

#include <iostream>     //cout()
#include <iomanip>      //setprecision() etc.
#include <stdexcept>    //runtime_error
#include <cstdio>       //getchar()
#include "RazorAHRS.h"

using namespace std;

//IMRemote
float yaw;
float pitch;
float roll;
int buttonState;

void on_error(const string &msg)
{
    cout << "  " << "ERROR: " << msg << endl;
}

void on_data(const float data[])
{
    
    //YAW_PITCH_ROLL data on serial
    cout << "  " << fixed << setprecision(3)
    << "Yaw = " << setw(6) << data[0] + 30 << "      Pitch = " << setw(6) << data[1] << "      Roll = " << setw(6) << data[2] << endl;
    
    yaw =  data[0] + 30;
    pitch =  data[1];
    roll =  data[2];
    //make data[3] (button data) an integer for easier access.
    int val = (int)(data[3]);
    
    //make button access public
    buttonState = val;
    
    switch (val){
        case 1:
            printf("up \n");
            break;
        case 2:
            printf("down \n");
            break;
        case 3:
            printf("left \n");
            break;
        case 4:
            printf("right \n");
            break;
        case 5:
            printf("center \n");
            break;
    }
}


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetCircleResolution(100);

    yawOffset = 0;
    myFont.loadFont("Arial Bold.ttf", 12);
    mySmallFont.loadFont("Arial Bold.ttf", 8);
        
    //IMRemote using YAW_PITCH_ROLL
    razor = new RazorAHRS(serial_port_name, on_data, on_error, RazorAHRS::YAW_PITCH_ROLL);
    imuSpeed = 20;
    
    //Scenes
    scenes.push_back(new channelOne());
    scenes.push_back(new channelTwo());
    scenes.push_back(new channelThree());
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    sceneNumber = 0;
    
    //Screen One particles
    for(int i = 0; i < 1000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0, 0);
        particles.push_back(myParticle);
    }
    
    //Screen Two particles
    for(int i = 0; i < 200; i++){
        particletwo myParticle;
        myParticle.setInitialCondition(ofRandom(0, ofGetWidth()), ofRandom(ofGetHeight()/3 - 20, ofGetHeight()/3 + 20), 0, 0);
        myparticles.push_back(myParticle);
    }
    bRepel = true;
    radius = 5;
    strength = 0.5f;
    
    //Xeno
    xenopointer.catchUpSpeed = 0.1f;
    xenopointer.xenoRadius = 3;
    
    imuRepulsionRadius = 1;
}

//--------------------------------------------------------------
void testApp::update(){
    
    //Reduces noise level from sensor
    xYaw = ofGetWidth()/2 + (yaw - yawOffset) * imuSpeed;
    yPitch = ofGetHeight()/2 + pitch * imuSpeed;
    
//    cout << xYaw << endl;
    //Mapping yaw and pitch (secondary) 
//    xYaw = ofMap(yaw - yawOffset, -30,30,0,ofGetWidth());
//    yPitch = ofMap(pitch, -50,50,0,ofGetHeight());
    
    
    //Channel One Particles
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addForce(-1.0, 0);
        
        if(bRepel){
            particles[i].addRepulsionForce(xenopointer.pos.x, xenopointer.pos.y, imuRepulsionRadius, 3.0);
        }
        else{
            particles[i].addAttractionForce(xenopointer.pos.x, xenopointer.pos.y, imuRepulsionRadius, 3.0);
        }
        
        if (particles[i].pos.x <= 0){
            particles[i].pos.x = ofGetWidth() + 10;
        }
        
        if (particles[i].pos.y > ofGetHeight()*2/3 + 20){
            particles[i].addForce(0,-1.0);
        }
        
        if (particles[i].pos.y < ofGetHeight()*2/3 - 20){
            particles[i].addForce(0,1.0);
        }
        
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
		particles[i].update();
    }
    
    //Channel Two Particles
    for (int i = 0; i < myparticles.size(); i++){
        myparticles[i].resetForce();
        myparticles[i].addForce(1.0, 0);
        if(bRepel){
            myparticles[i].addRepulsionForce(xenopointer.pos.x, xenopointer.pos.y, imuRepulsionRadius, 3.0);
        }
        else{
            myparticles[i].addAttractionForce(xenopointer.pos.x, xenopointer.pos.y, imuRepulsionRadius, 3.0);
        }
        
        if (myparticles[i].pos.x > ofGetWidth()){
            myparticles[i].pos.x = -10;
        }
        
        if (myparticles[i].pos.y > ofGetHeight()/3 + 20){
            myparticles[i].addForce(0,-1.0);
        }
        
        if (myparticles[i].pos.y < ofGetHeight()/3 - 20){
            myparticles[i].addForce(0,1.0);
        }
        myparticles[i].addDampingForce();
		myparticles[i].update();
    }
    
    for (int i = 0; i < myparticles.size(); i++){
        for(int j = 0; j < i; j++){
            myparticles[i].addRepulsionForce(myparticles[j], 20, 0.4);
			myparticles[i].addAttractionForce(myparticles[j], 50, 0.005);
        }
//        for (int j = 0; j < i; j++){
//            if (bRepel){
//                myparticles[i].addRepulsionForce(myparticles[j], radius, strength);
//            } else {
//                myparticles[i].addAttractionForce(myparticles[j], radius, strength);
//            }
//        }
    }
    
    //IMU Repulsion Radius
    if (sceneNumber == 2){
        buttonValue = buttonState;
        
        if(buttonValue != lastButtonValue){
            if(buttonValue == 3){
                for(int i = 0; i < particles.size(); i++){
                    particles[i].setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0, 0);
                }
            }
            if(buttonValue == 4){
                bRepel = !bRepel;
            }
            lastButtonValue = buttonValue;
        }
        if (roll < -30){
            imuRepulsionRadius ++;
        }
        if (roll > 30){
            imuRepulsionRadius --;
            if (imuRepulsionRadius <= 1){
                imuRepulsionRadius = 1;
            }
        }
        if (roll > 170 || roll < -170){
            imuRepulsionRadius = 1;
        }
    }
    
    xenopointer.xenoToPoint(xYaw, yPitch);
    
    if(sceneNumber == 2){

    }

    //Scenes
    scenes[sceneNumber]->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    //ButtonState is a int: 1up 2down 3left 4right 5center
    
    imuData =       "Yaw = " + ofToString(yaw, 0.0f) +
                    "\n\nPitch = " + ofToString(pitch, 0.0f) +
                    "\n\nRoll = " + ofToString(roll, 0.0f) +
                    "\n\nUp Button = Refresh Sketch" +
                    "\n\nLeft Button = Decrease Line Width" +
                    "\n\nRight Button = Increase Line Width" +
                    "\n\nTouch Pointer Below Screen = Other Menus";
    
    screenOneData = "Yaw = " + ofToString(yaw, 0.0f) +
                    "\n\nPitch = " + ofToString(pitch, 0.0f) +
                    "\n\nRoll = " + ofToString(roll, 0.0f) +
                    "\n\nUp Button = Main Menu" +
                    "\n\nCenter Button = Attraction " +
                    "\n\nLeft Button = Renew Particles" + 
                    "\n\nMapped Roll Right = Clockwise" +
                    "\n\nMapped Roll Left = Counter Clockwise";
    
    screenTwoData = "Yaw = " + ofToString(yaw, 0.0f) +
                    "\n\nPitch = " + ofToString(pitch, 0.0f) +
                    "\n\nRoll = " + ofToString(roll, 0.0f) +
                    "\n\nUp Button = Main Menu" +
                    "\n\nCenter Button = Add Particles" +
                    "\n\nRight Button = Repulsion / Attraction" + 
                    "\n\nLeft Button = Renew Bottom Particles" +
                    "\n\nRoll Right = Increase Radius" +
                    "\n\nRoll Left = Decrease Radius" +
                    "\n\nFlip Over = Restart Radius";
    
    ofSetColor(200,200,200);
    if(sceneNumber == 0){
        mySmallFont.drawString(imuData, 100, 100);
    }
    if(sceneNumber == 1){
        mySmallFont.drawString(screenOneData, 100, 100);
    }
    if(sceneNumber == 2){
        mySmallFont.drawString(screenTwoData, 100, 100);
    }
    
    //Down Button Calibrates the YAW for each Screen
    if(sceneNumber == 0 || sceneNumber == 1 || sceneNumber == 2){
        if(buttonState == 2){
            yawOffset = yaw;
        }
    }
    
    //Universal Button States (main menu, screen1, screen2)
    if(buttonState == 1){
        sceneNumber = 0;
    }
    else if (buttonState == 2){
        yawOffset = yaw;
    }
    else{
    }
    
    ofSetColor(255,255,255);
    
    //Screen Two **************************************************************
    if(sceneNumber == 2){
        //Bottom Particles
        for (int i = 0; i < particles.size(); i++){
            particles[i].draw();
        }
        
        //Top Particles
        ofNoFill();
        ofSetColor(200,200,200,50);
        ofCircle(xenopointer.pos, imuRepulsionRadius);
        ofFill();
        
        for (int i = 0; i < myparticles.size(); i++){
            ofSetColor(255,0,0);
            myparticles[i].draw();
        }
        
        if(buttonState == 5){
            myparticles.erase(myparticles.begin());
            particletwo myParticle;
            myParticle.setInitialCondition(xYaw, yPitch, 0, 0);
            myparticles.push_back(myParticle);
        }
    }
    //FFT Analyzing**************************************************************
    
    if(sceneNumber == 0){
        if(xYaw >= ofGetWidth()/2 - 370 && xYaw <= ofGetWidth()/2 - 170 && yPitch >= ofGetHeight() - 70 && buttonState == 5.0){
            sceneNumber = 1;
        }
        if(xYaw >= ofGetWidth()/2 + 170 && xYaw <= ofGetWidth()/2 + 370 && yPitch >= ofGetHeight() - 70 && buttonState == 5.0){
            sceneNumber = 2;
        }
    }
    scenes[sceneNumber]->draw(xYaw, yPitch, roll, buttonState);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key){
        case 'f':
            if(bFullScreen == true){
                ofSetFullscreen(true);
                bFullScreen = false;
            }
            else{
                ofSetFullscreen(false);
                bFullScreen = true;
            }
            break;
        case 'y':
            yawOffset = yaw;
            break;
    }

}


//--------------------------------------------------------------
void testApp::audioReceived(float * input, int bufferSize, int nChannels){
    


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}