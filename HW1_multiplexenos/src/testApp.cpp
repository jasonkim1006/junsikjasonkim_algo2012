#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
    ofEnableSmoothing();
    ofEnableAlphaBlending();
//    ofSetFrameRate(70);
    ofSetCircleResolution(100);
	ofSetVerticalSync(true);
	ofBackground(30,30,30);
	
	// set the position of the rectangle:
	
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
    
    
    
    for(int i = 0; i<10; i++){
        xenoCircles[i].circlepos.x = ofRandom(ofGetWidth());
        xenoCircles[i].circlepos.y = ofRandom(ofGetHeight());
    }
    
    
    
    //JASON
    for(int i =0; i<10; i++){
        circles[i].setup();
        circles[i].radius = 10;
        circles[i].angle = (360/10.0) * i;
        circles[i].dist = 200;
    }

}

//--------------------------------------------------------------
void testApp::update(){
    myRectangle.xenoToPoint(mouseX, mouseY);
    
    for(int i =0; i<10; i++){
        xenoCircles[i].xenoToPoint(mouseX, mouseY);
    }
    
    
    //JASON
    for(int i =0; i<10; i++){
        circles[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    myRectangle.draw();
    
    for(int i =0; i<10; i++){
        xenoCircles[i].draw();
    }
    
    
    
    //JASON
    ofPushMatrix();
    ofTranslate(mouseX, mouseY);
    for(int i = 0; i<10; i++){
        ofFill();
        ofSetColor(255);
        circles[i].draw();
    }
    ofPopMatrix();
    

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
    for(int i=0; i<10; i++){
        xenoCircles[i].circlecatchUpSpeed = 0.009f;
        ofPushMatrix();
        ofTranslate(mouseX, mouseY);
        xenoCircles[i].circlepos.x += ofRandom(-50,50);
        xenoCircles[i].circlepos.y += ofRandom(-50,50);
        
//        xenoCircles[i].circlepos.x -= 20;
//        xenoCircles[i].circlepos.y -= 20;
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for(int i=0; i<10; i++){
        ofPushMatrix();
            ofTranslate(mouseX, mouseY);
            xenoCircles[i].circlepos.x -= 20;
            xenoCircles[i].circlepos.y -= 20;
        ofPopMatrix();
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