#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    for (int i = 0; i < 33; i ++){
        myAngles[i] = ofRandom(360);
    }
    
    ofBackground(50, 50, 50);
        
    //colorful sparks
    for (int i = 0; i < 100; i++){
        particle myParticle;
        x_orig = ofRandom(-0.5, 0.5);
        y_orig = ofRandom(-0.5, 0.5);
//        myParticle.setInitialCondition(300, 300, ofRandom(-10,10), ofRandom(-10,10));
        myRadius = ofRandom(3,4);
//        myAngle = ofRandom(360);
        myVX = x_orig + myRadius * cos(myAngles[i]);
        myVY = y_orig + myRadius * sin(myAngles[i]);
        myParticle.setInitialCondition(ofGetWidth()/2 + ofRandom(-50,50), ofGetHeight()/2 + ofRandom(-50,50), myVX, myVY);
		//myParticle.damping = ofRandom(0.001, 0.05);
        particles.push_back(myParticle);
        
    }
    
    //white sparks
    for (int i = 0; i < 300; i++){
        particle myParticleTwo;
        x_orig = ofRandom(-1,1);
        y_orig = ofRandom(-1,1);
        myRadiusTwo = ofRandom(-5,5);
        myAngle = ofRandom(360);
        myVX2 = x_orig + myRadiusTwo * cos(myAngle);
        myVY2 = y_orig + myRadiusTwo * sin(myAngle);
        myParticleTwo.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, myVX2, myVY2);
        particlesTwo.push_back(myParticleTwo);
    }
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        //adds forces on x and y axes.
        particles[i].addForce(0.0, 0.25);
        //without this, there is no damping. will bounce forever
        particles[i].addDampingForce();
        particles[i].bounceOffWalls();
        //makes the movement
        particles[i].update();
    }
    
    
    for (int i = 0; i < particlesTwo.size(); i++){
        particlesTwo[i].resetForce();
        particlesTwo[i].addForce(0.0, 0.15);
        particlesTwo[i].addDampingForceTwo();
        particlesTwo[i].bounceOffWalls();
        particlesTwo[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < particles.size(); i++){
        ofNoFill();
        float myMappedX = ofMap(particles[i].pos.x, 0, ofGetWidth(), 0, 255);
        myColor.setSaturation(myMappedX);
        ofSetColor(myMappedX,200,200);    
        particles[i].draw();
    }

    for (int i = 0; i < particlesTwo.size(); i++){
        ofNoFill();
        float myMappedX = ofMap(particles[i].pos.x, 0, ofGetWidth(), 0, 255);
        ofSetColor(200, 200, myMappedX);     
        
        float lengthOfVel = ofDist(0, 0, particlesTwo[i].vel.x, particlesTwo[i].vel.y);
        float lengthOfVelMap = ofMap(lengthOfVel, 0, 2, 0, 10);
        float lengthOfVelMapRotate = ofMap(lengthOfVel, 0, 2, 0, 180);
        float angle = ofRandom(360);
        
        if (i%3 == 0){
            particlesTwo[i].draw();
        }
        
        if (i%3 == 1){
            ofPushMatrix();
                ofTranslate(particlesTwo[i].pos.x, particlesTwo[i].pos.y, 0);
                ofRotateZ(myAngles[i] * RAD_TO_DEG);
                ofRotateZ(lengthOfVelMapRotate);
                ofTriangle(0, -10, 20 + lengthOfVelMap/2.0, 0, 0, 10);
            ofPopMatrix();
        }
        
        if (i%3 == 2){
            ofFill();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofPushMatrix();
                ofTranslate(particlesTwo[i].pos.x, particlesTwo[i].pos.y, 0);
                ofRotateZ(myAngles[i] * RAD_TO_DEG);
                ofRect(0, 0, 10 + lengthOfVelMap/2.0, 10);
            ofPopMatrix();
        }
        
//        ofPushMatrix();
//            ofLine(particles[i].pos.x, particles[i].pos.y, particles[i-1].pos.x, particles[i-1].pos.y);
//        ofPopMatrix();
    
    }
    
    
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
    
    
    float myR = mouseY;
    float myRMap = ofMap(myR, 0, ofGetHeight(), 12, 0);
    
    
    for (int i = 0; i < particles.size(); i++){
        x_orig = ofRandom(-0.5, 0.5);
        y_orig = ofRandom(-0.5, 0.5);
        myRadius = ofRandom(3,4);
        myVX = x_orig + myRadius * cos(myAngles[i]);
        myVY = y_orig + myRadius * sin(myAngles[i]);
        myVX = x_orig + myRMap * cos(myAngles[i]);
        myVY = y_orig + myRMap * sin(myAngles[i]);
        particles[i].setInitialCondition(mouseX, mouseY, myVX, myVY);
        
    }
    
    for (int i = 0; i < particlesTwo.size(); i++){
        x_orig = ofRandom(-1,1);
        y_orig = ofRandom(-1,1);
        myAngle = ofRandom(360);
        myRadiusTwo = ofRandom(-5,5);
        myVX2 = x_orig + myRadiusTwo * cos(myAngle);
        myVY2 = y_orig + myRadiusTwo * sin(myAngle);
        particlesTwo[i].setInitialCondition(mouseX, mouseY, myVX2, myVY2);
    }

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