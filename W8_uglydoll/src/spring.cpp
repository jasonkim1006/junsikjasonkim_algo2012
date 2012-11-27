//
//  spring.cpp
//  W8_creaaature
//
//  Created by Jun Sik (Jason) Kim on 11/23/12.
//
//

#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	
    //JASON Hooke's Law f = -kx k -> spring constant x -> distance
    //distance -> distance - theirDistance
    //springiness 
    
	ofVec2f pta = particleA->pos;
	ofVec2f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
	
	particleA->addForce(frcToAdd.x, frcToAdd.y);
	particleB->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void spring::draw(){
	
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	//draws the line connecting two points in which it is pointed to. 
	ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
}