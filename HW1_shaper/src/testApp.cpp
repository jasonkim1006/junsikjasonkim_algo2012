#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
//    ofSetWindowShape(1200,800);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
	
	
	ofBackground(50);
	
    
    
	// now we are using multiple rectangles....
	// set the "a" and "b" positions of the
	for (int i = 0; i < 10; i++){
		myRectangles[i].posa.x = 0;
		myRectangles[i].posa.y = 10 + i*20;
		myRectangles[i].posb.x = ofGetWidth();
		myRectangles[i].posb.y = 10 + i*20;
		myRectangles[i].shaper = 0.4 + 0.2 * i;
        //JASON if shaper is < 0, then it starts fast, then goes slow.
        //JASON if shaper is > 0, then starts slow, then goes fast.
		myRectangles[i].interpolateByPct(0);	// start at 0 pct
	}
	pct = 0;							// a variable we can alter...
    
    
    
  
    
    
    //JASON CIRCLES
    for (int i = 0; i < 10; i++){
        myCircles[i].circleposa.x = ofGetWidth();
        myCircles[i].circleposa.y = 200 + i*30;
        myCircles[i].circleposb.x = 0;
        myCircles[i].circleposb.y = 250 + i*30;
        myCircles[i].circleshaper = 0.4 + 0.2 * i;
        myCircles[i].interpolateByPct(0);
    }
    circlepct = 0;
    
    for (int i = 0; i < 10; i++){
        myCircles1[i].circleposa.x = 0;
        myCircles1[i].circleposa.y = 10 + i*30;
        myCircles1[i].circleposb.x = ofRandom(ofGetWidth());
        myCircles1[i].circleposb.y = 0 + i*30;
        myCircles1[i].circleshaper = 0.4 + 0.2 * i;
        myCircles1[i].interpolateByPct(0);
    }
    circlepct1 = 0;
    
    for (int i = 0; i < 10; i++){
        myCircles2[i].circleposa.x = ofRandom(ofGetWidth());
        myCircles2[i].circleposa.y = 400 + i*30;
        myCircles2[i].circleposb.x = 0;
        myCircles2[i].circleposb.y = 450 + i*30;
        myCircles2[i].circleshaper = 0.4 + 0.2 * i;
        myCircles2[i].interpolateByPct(0);
    }
    circlepct2 = 0;
    
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
	pct += 0.003f;							// increase by a certain amount
	if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
	for (int i = 0; i < 10; i++){
		myRectangles[i].interpolateByPct(pct);		// go between pta and ptb
	}
    
    
    //JASON CIRCLES
    circlepct += 0.003f;
    if(circlepct > 1) circlepct =0;
    for (int i = 0; i < 10; i++){
        myCircles[i].interpolateByPct(circlepct);
    }
    
    circlepct1 += 0.002f;
    if(circlepct1 > 1) circlepct1 =0;
    for (int i = 0; i < 10; i++){
        myCircles1[i].interpolateByPct(circlepct1);
        myCircles1[i].circlecolor.b = powf(circlepct1*20,myCircles1[i].circleshaper);
    }
    
    circlepct2 += 0.002f;
    if(circlepct2 > 1) circlepct2 =0;
    for (int i = 0; i < 10; i++){
        myCircles2[i].interpolateByPct(circlepct2);
        myCircles2[i].circlecolor.r = powf(circlepct2*20,myCircles2[i].circleshaper);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
//    for (int i = 0; i < 10; i++){
//		//if (i == 3) ofSetColor(255,0,0);
//		myRectangles[i].draw();
//	}
	
//	ofSetColor(255,255,255);
//	for (int i = 0; i < 10; i++){
//		ofLine(0,i*20, ofGetWidth(), i*20);
//	}
    
    
//    printf("%f \n", myRectangles[9].pct);

    //JASON CIRCLES
    for (int i = 0; i < 10; i++){
        myCircles[i].draw();
        myCircles1[i].draw();
        myCircles2[i].draw();
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