//
//  particle.cpp
//  HW5_attractionrepulsion
//
//  Created by Jun Sik (Jason) Kim on 10/19/12.
//
//

#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
    setInitialCondition(0, 0, 0, 0);
    damping = 0.09f;
}

//------------------------------------------------------------
void particle::resetForce(){
    frc.set(0,0);
    //need to reset force everytime
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    frc.x = frc.x + x;
    //add in force in X and Y for this frame
    frc.y = frc.y + y;
    //frc is force, not friction.
}

//------------------------------------------------------------
void particle::addDampingForce(){
    // the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::addRepulsionForce( float px, float py, float radius, float strength){
    //JASON NOTES
    /*
     damping => force opposite of velocity
     velocity is a LINE
     
     Amount of force you feel is proportional to distance of object.
     smaller distance, the greater the force (think of magnets)
     
     magnitude => how far?
     
     radius of force
     
     part / whole
     magnitude / radius => ratio. We have a number that goes from 1 -> 0 (closer to particle)
     
     in order to make it from go from 0 to 1 in stead of 1 to 0, we do (1 - m / radius).
     
     
     we will NORMALIZE the line. => take vector, divide by length of vector.
     
     NORMALIZE => special vector with length of 1.
     Normalized vectors have same angle. Because we normalize everything, we can get angle.
     
     NORMALIZE => X = X/M, Y = Y/M => creates a UNIT VECTOR where length is 1.
     MAGNITUDE & DIRECTION
     
     PERPENDICULAR => x/y -> -y/x
     
     
     */
    
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    
    //take my position and subtract position of force
    ofVec2f diff = pos - posOfForce;
    //find difference between two points
    
    //if the difference is less than the radius size (inside the circle)
    if (diff.length() < radius){
        //(1 - m / radius)
        float pct = 1 - (diff.length() / radius);
        //change to unit vector (length of 1) -> can multiply strength!
        diff.normalize();
        //force
    
        frc.x += diff.x * pct * strength;
        frc.y += diff.y * pct * strength;
        
    }
}

//------------------------------------------------------------
void particle::addAttractionForce( float px, float py, float radius, float strength){
	
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = pos - posOfForce;
    
    float mySine = sin(ofGetElapsedTimef());
	float mappedSine = ofMap(mySine, -1, 1, 0, 1);
    
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.x * pct * strength + mySine/5.0 + ofRandom(-1,1);
		frc.y -= diff.y * pct * strength + mySine/5.0 + ofRandom(-1,1);
//        frc.x -= diff.x * pct * strength;
//        frc.y -= diff.y * pct * strength;
        
	}
	
}

//------------------------------------------------------------
void particle::addClockwiseForce( float px, float py, float radius, float strength){
	
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x -= diff.y * pct * strength;
		frc.y += diff.x * pct * strength;
	}
	
}

//------------------------------------------------------------
void particle::addCounterClockwiseForce( float px, float py, float radius, float strength){
	
	
	ofVec2f posOfForce;
	posOfForce.set(px, py);
	
	ofVec2f diff = pos - posOfForce;
	
	if (diff.length() < radius){
		float pct = 1 - (diff.length() / radius);
		diff.normalize();
		frc.x += diff.y * pct * strength;
		frc.y -= diff.x * pct * strength;
	}
	
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
    

}

//------------------------------------------------------------
void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
//    ofSetColor(255);
//    ofCircle(pos.x, pos.y, 3);
    
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    
    angle = atan2(dy, dx);
   
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    
    float myMappedX = ofMap(pos.x, 0, ofGetWidth(), 0, 255);
    float myMappedY = ofMap(pos.y, 0, ofGetHeight(), 150, 255);
    ofSetColor(myMappedY, 0, myMappedX, 75);
    
    float lengthofVel = ofDist(0, 0, vel.x, vel.y);
    float lengthofVelMap = ofMap(lengthofVel, 0, 2, 0, 10);
    
    ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        ofRotateZ(angle * RAD_TO_DEG);
//        ofRect(0,0,10,20);
//        ofTriangle(0, -10, 20 + lengthOfVelMap/2.0, 0, 0, 10);
        ofTriangle(0, -5, 10 + lengthofVelMap/2.0, 0, 0, 5);
    ofPopMatrix();
}

































