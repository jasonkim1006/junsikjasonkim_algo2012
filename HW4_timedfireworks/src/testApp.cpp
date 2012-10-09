#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    ofBackground(50, 50, 50);
    
    lastFireworkTime = ofGetElapsedTimef();
    
    font.loadFont("HelveticaLight.ttf", 10);
        
    //colorful sparks
    for (int i = 0; i < 100; i++){
        particle myParticle;
        
//        myParticle.setInitialCondition(300, 300, ofRandom(-10,10), ofRandom(-10,10));
        myRadius = ofRandom(3,4);
        myAngle = ofRandom(360);
        myVX = myRadius * cos(myAngle);
        myVY = myRadius * sin(myAngle);
        myParticle.setInitialCondition(ofGetWidth()/2 + ofRandom(-50,50), ofGetHeight()/2 + ofRandom(-50,50), myVX, myVY);
		//myParticle.damping = ofRandom(0.001, 0.05);
        particles.push_back(myParticle);
    }
    
    //white sparks
    for (int i = 0; i < 1000; i++){
        particle myParticleTwo;
        myRadiusTwo = ofRandom(-5,5);
        myAngle = ofRandom(360);
        myVX2 = myRadiusTwo * cos(myAngle);
        myVY2 = myRadiusTwo * sin(myAngle);
        myParticleTwo.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, myVX2, myVY2);
        particlesTwo.push_back(myParticleTwo);
    }
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        //adds forces on x and y axes.
        //        particles[i].addForce(0.0, -0.28);
        //without this, there is no damping. will bounce forever
        particles[i].addDampingForce();
        //        particles[i].bounceOffWalls();
        //makes the movement
        particles[i].update();
    }
    
    
    for (int i = 0; i < particlesTwo.size(); i++){
        particlesTwo[i].resetForce();
        particlesTwo[i].addDampingForceTwo();
        //        particlesTwo[i].bounceOffWalls();
        particlesTwo[i].update();
    }
    
    float timeSinceLastFirework = ofGetElapsedTimef() - lastFireworkTime;
    if(timeSinceLastFirework >= 5.0){
        for (int i = 0; i < particles.size(); i++){
            myRadius = ofRandom(3,4);
            myAngle = ofRandom(360);
            myVX = myRadius * cos(myAngle);
            myVY = myRadius * sin(myAngle);

            particles[i].setInitialCondition(ofGetWidth()/2 + ofRandom(-50,50), ofGetHeight()/2 + ofRandom(-50,50), myVX, myVY);

        }
        
        for (int i = 0; i < particlesTwo.size(); i++){
            myAngle = ofRandom(360);
            myRadiusTwo = ofRandom(-5,5);
            myVX2 = myRadiusTwo * cos(myAngle);
            myVY2 = myRadiusTwo * sin(myAngle);
            particlesTwo[i].setInitialCondition(ofGetWidth()/2 + ofRandom(-50,50), ofGetHeight()/2 + ofRandom(-50,50), myVX2, myVY2);
        }
        lastFireworkTime = ofGetElapsedTimef();
    }
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    


}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofSetColor(255,100);
    
    for (int i = 0; i < particles.size(); i++){
        myColor.r = ofRandom(255);
        myColor.g = ofRandom(255);
        myColor.b = ofRandom(255);
        myColor.a = ofRandom(255);
        ofSetColor(myColor);
        particles[i].circleRadius = 4;
        particles[i].draw();
    }

    for (int i = 0; i < particlesTwo.size(); i++){
        ofSetColor(200,200,200,ofRandom(50));
        particlesTwo[i].draw();
        
    }
    
    
    float timeUntilFirework = 5 - (ofGetElapsedTimef() - lastFireworkTime);
    ofSetColor(255);
    font.drawString("Next firework in "+ofToString(timeUntilFirework,1)+" seconds", 20, 20);
    


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
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].setInitialCondition(mouseX, mouseY, ofRandom(-10,10), ofRandom(-10,10));
//    }

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