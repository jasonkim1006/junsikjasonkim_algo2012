//
//  particle.h
//  HW5_attractionrepulsion
//
//  Created by Jun Sik (Jason) Kim on 10/19/12.
//
//

#ifndef __HW5_attractionrepulsion__particle__
#define __HW5_attractionrepulsion__particle__

#include "ofMain.h"

class particle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc; //also known as acceleration
    ofVec2f prevPos;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    //resets for because we do not want to accumulate
    void addForce(float x, float y);
    //move it
    void addDampingForce();
    //friction
    void setInitialCondition(float px, float py, float vx, float vy);
    //where does it start and in what velocity
    void update();
    void draw();
    void addRepulsionForce(float px, float py, float radius, float strength);
    //pushes
    void addAttractionForce(float px, float py, float radius, float strength);
    //pulls
    void addClockwiseForce(float px, float py, float radius, float strength);
    //rotate
    void addCounterClockwiseForce(float px, float py, float radius, float strength);
    //opposite rotation
    
    float damping;
    //set friction amount
    float angle;
    
    ofColor myColor;
    void drawCircle();
    void bounceOffWalls();
    
protected:
private:
    
};

#endif /* defined(__HW5_attractionrepulsion__particle__) */
