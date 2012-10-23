#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(20, 20, 20);
    ofSetCircleResolution(100);
    
    for (int i = 0; i < 5000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        particles.push_back(myParticle);
    }
    isRepulsive = false;
    
    windblows.setup();
    mySound.setup(this, 0, 2, 44100, windblows.bufferSize, 4);
    
}

//--------------------------------------------------------------
void testApp::update(){
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    windblows.update();
    windRadius = windblows.scaledVol * 300.0f;
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        
        if(isRepulsive == false){
            particles[i].addAttractionForce(mouseX, mouseY, windRadius, 0.4);
        }
        
        else if(isRepulsive == true){
            particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.3);
        }

		particles[i].addDampingForce();
		particles[i].update();
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0x000000);
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    ofSetColor(200,200,200);
    ofDrawBitmapString("'r' to reset\n'a' to change force type", 50, 50);
    
    switch(forceType){
        case 0: ofDrawBitmapString("force type: Wind Blow (Audio Input)", 50, 80);
            break;
        case 1: ofDrawBitmapString("force type: Repulsion", 50, 80);
            break;
    }
    
    ofNoFill();
    ofSetColor(100);
    ofCircle(mouseX, mouseY, windRadius);
    ofFill();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r'){
        for (int i = 0; i < 2000; i++){
            particle myParticle;
            myParticle.setInitialCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
            particles.push_back(myParticle);
            if(particles.size() > 2000){
                particles.erase(particles.begin());
            }
        }
    }
    else if (key == 'a'){
        forceType ++;
        forceType %= 2;
        isRepulsive = !isRepulsive;
    }
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addRepulsionForce(mouseX, mouseY, 150, 1);
        particles[i].addDampingForce();
        particles[i].update();
    }

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

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
	
	float curVol = 0.0;
	int numCounted = 0;
    
	for (int i = 0; i < bufferSize; i++){
		windblows.left[i] = input[i*2]*0.5;
		windblows.right[i] = input[i*2+1]*0.5;
        
		curVol += windblows.left[i] * windblows.left[i];
		curVol += windblows.right[i] * windblows.right[i];
		numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt(curVol);
	
	windblows.smoothedVol *= 0.93;
	windblows.smoothedVol += 0.07 * curVol;
	
	windblows.bufferCounter++;
}