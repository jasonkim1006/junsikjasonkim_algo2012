#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
	ofSoundStreamSetup(0,2,this, 44100, BUFFER_SIZE, 4);
	
	left = new float[BUFFER_SIZE];
	right = new float[BUFFER_SIZE];
	
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
	
	ofSetFrameRate(60);
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(0,0,0);

}

//--------------------------------------------------------------
void testApp::draw(){
//    ofBackground(255, 255, 255, 200);
	float avg_power = 0.0f;
    
	/* do the FFT	*/
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
    
	for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
		freq[i] = magnitude[i];
	}
	
	FFTanalyzer.calculate(freq);
	
    
    //	for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){
    //		ofRect(200+(i*40),600,4,-freq[i]*10.0f);
    //	}
    
    
    //LEFT RIGHT Circles
    for(int i = ofGetHeight()/3; i < ofGetHeight()*2/3; i++){
        ofSetColor(30,120,190);
        ofNoFill();
        ofCircle(left[i]*300, i, ofRandom(1,2));
        ofCircle(ofGetWidth()-right[i]*300,i,ofRandom(1,2));
        ofFill();
    }
    
    
    //FFT outer circles
    ofSetColor(150,150,150,100);
    ofSetLineWidth(ofRandom(1,3));
    
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofNoFill();
        ofCircle(ofGetWidth()/3-50,ofGetHeight()/2,FFTanalyzer.peaks[i] *6);
        cout << FFTanalyzer.peaks[i] << endl;
    }
    
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofNoFill();
        ofCircle(ofGetWidth()*2/3+50,ofGetHeight()/2,FFTanalyzer.peaks[i] *6);
    }
    ofFill();
    
    
    //TOP and DOWN
    ofSetLineWidth(ofRandom(0,10));
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofLine(200+(i*40),0,200+(i*40),FFTanalyzer.averages[i] * 6);
    }
    
    ofPushMatrix();
    
    ofRotateY(180);
    ofTranslate(-ofGetWidth(),0);
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofLine(200+(i*40),ofGetHeight(),200+(i*40),ofGetHeight()-FFTanalyzer.averages[i] * 6);
    }
    
    ofSetColor(255,255,0);
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofRect(190+(i*40),ofGetHeight()-FFTanalyzer.peaks[i] * 6,20,-10);
        
    }
    ofPopMatrix();
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofRect(190+(i*40),FFTanalyzer.peaks[i] * 6,20,-10);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
    }

}

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
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