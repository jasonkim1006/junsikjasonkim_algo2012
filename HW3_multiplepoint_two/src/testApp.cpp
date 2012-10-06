#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofBackground(255,255,255);
    ofEnableAlphaBlending();
    

    TPR.setup();
    playbackStartTime = 0;
    
    for (int i = 0; i < TPRS.size(); i++){
        TPRS[i].setup();
    }
    
    //SOUND
    loopingSound.loadSound("drawbar_c4_a.aif");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    TPR.draw();
    
//    ofSetColor(255,255,255);
//    currentLine.draw();
    
    if (TPR.bHaveADrawing()){
        
        //map to sin -> going and coming back
        float sinVal = sin(ofGetElapsedTimef());
		float sinPct = ofMap(sinVal, -1,1,0,1);
//		float timeToCheck = sinPct * TPR.getDuration();
        
        //time of sketch
        //UNCOMMENT FOR LOOP
        float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
        
        //if time to check is greater than the duration it took to draw sketch, subtract the duration until timetocheck is less than duration
        //this section is needed for the circle to keep drawing.
        //playbackStartTime = ofGetElapsedTimef once the mouse is released (ofGetElapsedTimef - playbackStartTime initially equals 0)
        while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
            timeToCheck -= TPR.getDuration();
            //ex) if drawing was 3 seconds, if timetocheck is over 3 seconds (3.1), then subtract 3 and make it 0.1.
        }
        
        //position & velocity of timeToCheck
        ofPoint pos = TPR.getPositionForTime(timeToCheck);
        ofPoint posbehind = TPR.getBehindPositionForTime(timeToCheck);
        ofPoint vel = TPR.getVelocityForTime(timeToCheck);
        
        //since velocity is a line, we want to know how long it is.
        float lengthOfVel = ofDist(0, 0, vel.x, vel.y);
        //distance formula
        
        TPR.draw();
        
        ofFill();
		ofSetColor(255,0,0);
//		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
        
        //SOUND!
        float soundVolume = ofMap(lengthOfVel, 0, 200, 0, 1);
        loopingSound.setVolume(soundVolume);
        
        float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
        loopingSound.setSpeed(pitch);
        
        float pan = ofMap(pos.x, 0, (float)ofGetWidth(), -1, 1);
        loopingSound.setPan(pan);
        //ENDSOUND!
        
        
        /*
        //BACKGROUND!
        float bgColor = ofMap(pos.y, 0, ofGetHeight(), 50, 200);
        ofFill();
        ofSetColor(bgColor, bgColor, bgColor);
        ofRect(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
        ofSetColor(255-bgColor, 255-bgColor, 255-bgColor);
        ofRect(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()-100, ofGetHeight()-100);
        ofSetColor(bgColor, bgColor, bgColor);
        ofRect(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()-150, ofGetHeight()-150);
        //ENDBACKGROUND!
         
        //        ofBackground(bgColor, bgColor, bgColor);
         
        //CIRCLE!
        ofFill();
        ofSetColor(200,200,0);
        //circle radius is controlled by length of Vel
        ofCircle(posbehind.x, posbehind.y, 2+lengthOfVel/5.0);
        //ENDCIRCLE!

         
        //CIRCLE2!
        float myCircleRadius = sin(ofGetElapsedTimef());
        float myMappedRadius = ofMap(myCircleRadius, -1, 1, 1, 255);
        ofFill();
        ofSetColor(200,100,50,myMappedRadius);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, myMappedRadius);
        //ENDCIRCLE2

        
        
        
        //RECTANGE!
        float angle = atan2(vel.y, vel.x);
        float lengthVel = ofDist(0, 0, vel.x, vel.y);
        
        ofFill();
        ofSetColor(80,150,200);
        ofSetRectMode(OF_RECTMODE_CENTER);
        
        ofPushMatrix();
            ofTranslate(pos.x, pos.y, 0);
            ofRotateZ(angle * RAD_TO_DEG);
            ofRect(0, 0, 50 + lengthVel/2.0, 50);

        
            //TRIANGLE!
            ofFill();
            ofSetColor(10,150,150);
            ofPushMatrix();
            ofTranslate(lengthVel/2.0, 0);
                ofTriangle(0, -20, 20 + lengthVel/2.0, 0, 0, 20);
            ofPopMatrix();
            
            //ENDTRIANGLE!
        ofPopMatrix();
        //ENDRECTANGLE!
        */

    }
    
    for (int i = 0; i < TPRS.size(); i++){
        TPRS[i].draw();
        
        if(TPRS[i].bHaveADrawing()){
            
            float timeToCheck = ofGetElapsedTimef() - playbackStartTimeOne[i];
            while (timeToCheck > TPRS[i].getDuration() && TPRS[i].getDuration() > 0){
                timeToCheck -= TPRS[i].getDuration();
            }
            
            ofPoint pos = TPRS[i].getPositionForTime(timeToCheck);
            ofPoint vel = TPRS[i].getVelocityForTime(timeToCheck);
            
            float angle = atan2(vel.y, vel.x);
            float lengthOfVel = ofDist(0,0,vel.x,vel.y);
            
            ofFill();
            ofSetColor(255,0,0);
//            ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            
            
            if (i%3 == 0){
                ofSetColor(0,255,0);
                ofPushMatrix();
                    ofTranslate(pos.x, pos.y, 0);
                    ofRotateZ(angle * RAD_TO_DEG);
                    ofTriangle(0, -20, 20 + lengthOfVel/2.0, 0, 0, 20);
                ofPopMatrix();
            }
            
            if (i%3 == 1){
                ofSetColor(255,0,0);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            if (i%3 == 2){
                ofSetColor(80,150,200);
//                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofPushMatrix();
                    ofTranslate(pos.x, pos.y, 0);
                    ofRotateZ(angle * RAD_TO_DEG);
                    ofRect(0, 0, 50 + lengthOfVel/2.0, 50);
                ofPopMatrix();
            }
        }
        
        
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
    TPR.addPoint(x, y);
//    currentLine.addVertex(x,y);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    TPR.startDrawing(x, y);
//    currentLine.addVertex(x,y);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    TPR.endDrawing();
    TPRS.push_back(TPR);
    playbackStartTimeOne.push_back(playbackStartTime);
    playbackStartTime = ofGetElapsedTimef();
    TPR.clear();
    
//    lines.push_back(currentLine);
//    currentLine.clear();
    
    if (TPRS.size() > 10){
        TPRS.erase(TPRS.begin());
        playbackStartTimeOne.erase(playbackStartTimeOne.begin());
    }

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