#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	
	// set background:
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 0;
	myRectangle.posa.y = 100;
	myRectangle.posb.x = ofGetWidth();
	myRectangle.posb.y = 100;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
    
    
    //JASON mouse click is odd or even
    counter = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
	// to see pct in the console
	printf("%f \n", pct);
    
    //	pct += 0.001f;							// increase by a certain amount
    pct += 0.03f;
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}
	myRectangle.interpolateByPct(pct);		// go between pta and ptb
    


}

//--------------------------------------------------------------
void testApp::draw(){

    
    //JASON if even clicks, color is red
    if(counter % 2 == 0){
        ofSetColor(255,100,100);
        ofCircle(mouseX, mouseY, 20);
        ofLine(myRectangle.posa.x, myRectangle.posa.y, myRectangle.posb.x, myRectangle.posb.y);
    
    //JASON if odd clicks, color is green
    }
    if(counter % 2 != 0){
        ofSetColor(100, 255, 100);
        ofCircle(mouseX, mouseY, 20);
        ofLine(myRectangle.posa.x, myRectangle.posa.y, myRectangle.posb.x, myRectangle.posb.y);
    }
    
    myRectangle.draw();

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
    mouseIsDown = true;
    counter += 1;
    
    //JASON if even clicks, change posa
    if (counter % 2 == 0){
        myRectangle.posa.x = x;
        myRectangle.posa.y = y;
    
	}
    
    //JASON if odd clicks, change posb
    if (counter % 2 != 0){
        myRectangle.posb.x = x;
        myRectangle.posb.y = y;
    }

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouseIsDown = false;
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