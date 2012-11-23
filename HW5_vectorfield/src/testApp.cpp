#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(20, 20, 20);
    
    
    for (int i = 0; i < 2000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
        particles.push_back(myParticle);
        particlesTwo.push_back(myParticle);
    }
    
    
    //mapping value to ofGetWidth() and ofGetHeight()
    //	VF.setupField(102, 76,ofGetWidth(), ofGetHeight());
    VF.setupField(150, 100, ofGetWidth(), ofGetHeight());
    //setting up vector field. .setupField(innerW, innerH, outerW, outerH)
    
    
    //the higher number, the messy, almost like length of vectorfield
    //	VF.randomizeField(6.5);
    VF.randomizeField(0.1);
}

//--------------------------------------------------------------
void testApp::update(){
    
    mySine = sin(ofGetElapsedTimef());

    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        //get the force from the vector field

        ofVec2f frc;
        //get the force from position and add the force to the particles
        frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
        particles[i].addForce(frc.x, frc.y);
//        particles[i].addForce(frc.x, frc.y);
        particles[i].addDampingForce();
        particles[i].bounceOffWalls();
        particles[i].update();
    }
    
    for (int i = 0; i < particlesTwo.size(); i++){
        particlesTwo[i].resetForce();
        ofVec2f frc2;
        frc2 = VF.getForceFromPos(particlesTwo[i].pos.x, particlesTwo[i].pos.y);
        particlesTwo[i].addForce(frc2.x, frc2.y);
        particlesTwo[i].addDampingForce();
        particles[i].bounceOffWalls();
        particlesTwo[i].update();
    }

    if (bFade == true) VF.fadeField(0.99f);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(30,30,30,230);
    VF.draw();
    

    
    for (int i = 0; i < particlesTwo.size(); i++){
        particlesTwo[i].drawCircle();
    }
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    ofDisableAlphaBlending();
    
    ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
	
	
	ofSetColor(255,255,130);
	switch (drawingStyle){
        case 0: ofDrawBitmapString("drawing mode: mouse dragged", 50, 90);
			break;
		case 1: ofDrawBitmapString("drawing mode: inward", 50, 90);
			break;
		case 2: ofDrawBitmapString("drawing mode: outward", 50, 90);
			break;
		case 3: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
			break;
		case 4: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90);
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 5;
	} else if (key == 'f'){
		bFade = !bFade;
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
    float diffx = x - prevMouseX;
    float diffy = y - prevMouseY;
    
    if (button == 0) {
		switch (drawingStyle){
            case 0: VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 60, 0.3f);
                break;
			case 1: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
				break;
			case 2: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 4: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
		}
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
		
	}
    
    prevMouseX = x;
    prevMouseY = y;
    
    

    
    
    
    
//    if (button == 0){
//        VF.addOutwardCircle(x, y, 100, 0.3);
//    }
//    else {
//        VF.addCounterClockwiseCircle(x, y, 200, 0.3);
//    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x;
	prevMouseY = y;
    
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