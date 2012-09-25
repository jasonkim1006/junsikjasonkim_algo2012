#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    ofBackground(0);
    
    ofSetFrameRate(60);
    
    ofSoundStreamSetup(2, 0, this, 44100, 256, 4);
    
    frequency								= 440;
	position								= 0;
	positionAdder							= (frequency / 44100.0) * TWO_PI;
	
	frequencyModulator						= 0;
	positionModulator						= 0;
	positionModulatorAdder					=  (frequencyModulator / 44100.0) * TWO_PI;
	
	modulator								= 0;
	sample									= 0;
    
    myradar.angle = 0;
    myradar.width = 5;
    myradar.speed = 0.01;


}

//--------------------------------------------------------------
void testApp::update(){
    myradar.update();
    myradar.speed = (0.5*modulator*frequency);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    myradar.draw();


}

// -------------------------------
void testApp::audioRequested( float *output, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){		
		modulator	=  ofMap(sin (positionModulator), -1,1, 0,1); 
		positionModulator += positionModulatorAdder;
		sample		= sin( position ) * modulator; 
		position	+= positionAdder;               
		output[i * 2 + 0] = sample;			
		output[i * 2 + 1] = sample;			
	}
	
	while (position > TWO_PI) {
		position -= TWO_PI;
	}
	
	while (positionModulator > TWO_PI){
		positionModulator -= TWO_PI;
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
    
    frequency = x - ofGetWidth()/2;
	positionAdder = (frequency / 44100.0) * TWO_PI;

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