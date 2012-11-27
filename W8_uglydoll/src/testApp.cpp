#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
//    ofBackground(179, 215, 65);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    bFullScreen = true;
    bSavePdf = false;
    

    
    
    for (int i = 0; i < 100; i++){
        creature myCreature;
        float size;
        ofColor myColor;
        float hue, sat, bri;
        
        if(i<5){
            hue = 20;
            sat = 20;
            bri = 150;
            size = 50;
        }
        else if(i>10 && i<30){
            hue = 0;
            sat = 200;
            bri = 200;
        }
        else{
            hue = ofRandom(0,200);
            sat = 150;
            bri = 200;
        }
        myColor = ofColor::fromHsb(hue, sat, bri, 200);
        size = ofRandom(5,20);
        myCreature.setup(myColor,size);
        creatures.push_back(myCreature);
    }
    
    for (int i = 0; i < 4; i++){
        creature myCreature;
        float size;
        ofColor myColor;
        float hue, sat, bri;
        hue = ofRandom(0,200);
        sat = 150;
        bri = 200;
        myColor = ofColor::fromHsb(hue, sat, bri, 200);
        size = 70;
        myCreature.setup(myColor,size);
        creatures.push_back(myCreature);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < creatures.size(); i++){
		creatures[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (bSavePdf == true){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }

    for (int i = 0; i < creatures.size(); i++){
		creatures[i].draw();
    }
    
    ofSetColor(0, 0, 0);
//    ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'\n'p' to save to pdf", 50, 50);
    
    if( bSavePdf ){
		ofEndSaveScreenAsPDF();
        bSavePdf = false;
	}
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
//    if (key == '1') {
//        ofSetFullscreen(true);
//    }
    
    if (key == 'p'){
        
        bSavePdf = true;
    }

    switch (key){
        case 'f':
            if (bFullScreen == true){
                ofSetFullscreen(true);
                bFullScreen = false;
            }
            else if (bFullScreen == false){
                ofSetFullscreen(false);
                bFullScreen = true;
            }
            
            break;
            
        case ' ':
            setup();
            break;
            

//		case ' ':
//			// reposition everything:
//			for (int i = 0; i < particles.size(); i++){
//				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//			}
//			break;
	}
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
	for (int i = 0; i < creatures.size(); i++) {
		creatures[i].moveMouse(x, y);
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//    particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
     particle myParticle;
     myParticle.setInitialCondition(x,y,0,0);
     particles.push_back(myParticle);*/


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//    particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
//    particles[0].bFixed = false; 

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