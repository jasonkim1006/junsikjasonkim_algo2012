#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    ofBackground(0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    float sinOfTime				= sin( ofGetElapsedTimef() );
//	float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
//	
//	float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
//	float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
	
    //JASON background goes from 0 - 255 (RGB))
//    ofBackground(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);
    
    //JASON rectangle goes from 255 - 0 (RGB))
//	ofSetColor(sinOfTimeMapped2, sinOfTimeMapped2, sinOfTimeMapped2);
//	ofRect(100,100,ofGetWidth()-200, ofGetHeight()-200);
    

    float zoominout = sin(ofGetElapsedTimef() * 2);
    float radiusmap = ofMap(zoominout, -1, 1, 1, 6);
    float radiusmap2 = ofMap(zoominout, -1, 1, 6, 1);
    float zoominoutmapped = ofMap(zoominout, -1, 1, 0, 150);
    float zoomoutinmapped = ofMap(zoominout, 1, -1, 0, 150);
    
    for(int i = 0; i<NUM_CIRCLES; i++){
        mycircles[i].color.r = 255 * (i/10.0);
        mycircles[i].color.g = 255 * (i/10.0);
        mycircles[i].color.b = 255 * (i/10.0);
        //JASON distance from middle point
//        mycircles[i].radius = 30 + i * 10;
        mycircles[i].radius = zoomoutinmapped + i * 10;
        //JASON rotation speed
        mycircles[i].angle = ((ofGetElapsedTimef()/90.0)*(360.0/NUM_CIRCLES)*(i+1));
        mycircles[i].draw();
        mycircles[i].circleradius = radiusmap2;
        mycircles[i].drawLine();
    }
    
    for(int i = 0; i<NUM_CIRCLES; i++){
        mycircles2[i].color.r = 255 * (i/10.0);
        mycircles2[i].color.g = 1 * (i/10.0);
        mycircles2[i].color.b = 1 * (i/10.0);
        
        mycircles2[i].radius = zoominoutmapped + i * 10;
        //JASON rotation speed
        mycircles2[i].angle = (-(ofGetElapsedTimef()/90.0)*(360.0/NUM_CIRCLES)*(i+1));
        mycircles2[i].draw();
        mycircles2[i].circleradius = radiusmap;
    }
    for(int i = 0; i<NUM_CIRCLES; i++){
        mycircles3[i].color.r = 255 * (i/10.0);
        mycircles3[i].color.g = 255 * (i/10.0);
        mycircles3[i].color.b = 255 * (i/10.0);
                
        mycircles3[i].radius = zoomoutinmapped + i * 10;
        //JASON rotation speed
        mycircles3[i].angle = ((ofGetElapsedTimef()/90.0)*(360.0/NUM_CIRCLES)*(i+1));
        mycircles3[i].draw();
        mycircles3[i].circleradius = radiusmap2;
    }
    for(int i = 0; i<NUM_CIRCLES; i++){
        mycircles4[i].color.r = 255 * (i/10.0);
        mycircles4[i].color.g = 1 * (i/10.0);
        mycircles4[i].color.b = 1 * (i/10.0);
        
        mycircles4[i].radius = zoominoutmapped + i * 10;
        //JASON rotation speed
        mycircles4[i].angle = (-(ofGetElapsedTimef()/90.0)*(360.0/NUM_CIRCLES)*(i+1));
        mycircles4[i].draw();
        mycircles4[i].circleradius = radiusmap;
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