#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(20, 20, 20);
    
    for (int i = 0; i < 5000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        //		myParticle.damping = ofRandom(0.01, 0.05);
        particles.push_back(myParticle);
    }
    isRepulsive = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        
//        particles[i].addForce(0.1,0.1);
        if(isRepulsive == false){
            particles[i].addAttractionForce(mouseX, mouseY, 300, 0.4);
//            particles[i].addClockwiseForce(mouseX, mouseY, 300, 0.5);
        }
        
        else if(isRepulsive == true){
            particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.3);
        }
//		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.3);
        
        //particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
		//particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);
		
		//particles[i].addForce(0,0.04);  // gravity
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
        case 0: ofDrawBitmapString("force type: Sine Attraction", 50, 80);
            break;
        case 1: ofDrawBitmapString("force type: Repulsion", 50, 80);
            break;
    }
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