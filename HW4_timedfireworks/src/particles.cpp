//
//  particles.cpp
//  HW4_fireworks
//
//  Created by Jun Sik (Jason) Kim on 10/5/12.
//
//

#include "particles.h"

//------------------------------------------------------------
particle::particle(){
    
    //initialize particles
    setInitialCondition(0, 0, 0, 0);
    damping = 0.04f;
    dampingTwo = 0.02f;
    circleRadius = 3;
    
}

//------------------------------------------------------------
void particle::resetForce(){
    //resetting force every frame (we are doing pixels per frame) -> no accumulation
    frc.set(0,0);

}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame
    frc.x = frc.x + x;
    frc.y = frc.y + y;
    
    
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
void particle::addDampingForceTwo(){
    
    // the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
    
    frc.x = frc.x - vel.x * dampingTwo;
    frc.y = frc.y - vel.y * dampingTwo;
    
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    
    //pos, vel = ofPoint. Stores px, py and vx, vy into ofPoint
    pos.set(px, py);
    vel.set(vx, vy);
    
}


//------------------------------------------------------------
void particle::update(){
    
    //frc = acceleration
    
    vel = vel + frc;
    pos = pos + vel;
    
}


//------------------------------------------------------------
void particle::draw(){
    
    ofCircle(pos.x, pos.y, circleRadius);
    
}

//------------------------------------------------------------
void particle::bounceOffWalls(){
    
    //sometimes it makes sense to damp, when we hit... for now, we don't
    
    bool bDampedOnCollision = false;
    bool bDidICollide = false;
    
    //what are walls?
    float minx = 0 + circleRadius;
    float miny = 0 + circleRadius;
    
    float maxx = ofGetWidth() - circleRadius;
    float maxy = ofGetHeight() - circleRadius;
    
    if (pos.x > maxx){
        pos.x = maxx; //prevents circles getting stuck on the edges. moves to edge
        vel.x *= -1;
        bDidICollide = true;
    }
    else if (pos.x < minx){
        pos.x = minx; //prevents circles getting stuck on the edges. moves to edge
        vel.x *= -1;
        bDidICollide = true;
    }
    if (pos.y > maxy){
        pos.y = maxy;
        vel.y *= -1;
        bDidICollide = true;
    }
    else if (pos.y < miny){
        pos.y = miny;
        vel.y *= -1;
        bDidICollide = true;
    }
    
    if(bDidICollide == true && bDampedOnCollision == true){
        //didnt deal with bDampedOnCollision yet.
        //this creates damping if circles hit the wall. 
        vel *= 0.9;
    }
    
}

