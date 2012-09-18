#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofBackground(30);
    
    ofSetWindowShape(600,600);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    font.loadFont("HelveticaLight.ttf", 10);

    
    // set the "a" and "b" positions of the rectangle...
	
	myRectangleSlow.posa.x = 0;
	myRectangleSlow.posa.y = 100;
	myRectangleSlow.posb.x = ofGetWidth();
	myRectangleSlow.posb.y = 100;
	myRectangleSlow.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
    
    
    myRectangleFast.posa.x = 0;
	myRectangleFast.posa.y = 200;
	myRectangleFast.posb.x = ofGetWidth();
	myRectangleFast.posb.y = 200;
	myRectangleFast.interpolateByPct(0);	// start at 0 pct
	pct2 = 0;
    
    myTime = ofGetElapsedTimeMillis() + 1000;
    
    slowX = 0;
    fastX = 0;
    
    //JASON slow x = 0.03125 (1/32) inches / second (0.0017756 miles / hour)
    
    //JASON fast x = 16.2 inches / second (0.92 miles / hour)


}

//--------------------------------------------------------------
void testApp::update(){
    
    myTime = ofGetElapsedTimeMillis();
    
    
    // to see pct in the console
//	printf("%f \n", pct);
    
    //SLOW RECTANGLE
    //	pct += 0.001f;							// increase by a certain amount
    pct += 0.00005f;
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}
	myRectangleSlow.interpolateByPct(pct);		// go between pta and ptb
    
    
    //FAST RECTANGLE
    
    pct2 += 0.032f;
	if (pct2 > 1) {
		pct2 = 0;							// just between 0 and 1 (0% and 100%)
	}
	myRectangleFast.interpolateByPct(pct2);
    
    if(ofGetElapsedTimeMillis() == 1000){
        slowX = myRectangleSlow.pos.x;
        fastX = myRectangleFast.pos.x;
    }
    



}

//--------------------------------------------------------------
void testApp::draw(){

    
   
    ofSetColor(255);
    font.drawString("My time is "+ofToString(myTime,1)+" seconds", 20, 20);
    
    
    myRectangleSlow.draw();
    myRectangleFast.draw();
    

    
    ofSetColor(200,200,200);
    ofRect(slowX, 300, 20,20);
    ofRect(fastX, 500, 20,20);

    cout<< myTime <<endl;

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