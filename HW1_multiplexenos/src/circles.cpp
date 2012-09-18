//
//  circles.cpp
//  HW1_multiplexenos
//
//  Created by Jun Sik (Jason) Kim on 9/18/12.
//
//

#include "circles.h"

//------------------------------------------------------------------
circles::circles(){
	circlecatchUpSpeed = 0.01f;
}

//------------------------------------------------------------------
void circles::draw() {
    ofSetColor(23,250,250);
    ofCircle(circlepos.x, circlepos.y, 12);
}

//------------------------------------------------------------------
void circles::xenoToPoint(float catchX, float catchY){
	circlepos.x = circlecatchUpSpeed * catchX + (1-circlecatchUpSpeed) * circlepos.x;
	circlepos.y = circlecatchUpSpeed * catchY + (1-circlecatchUpSpeed) * circlepos.y;
}
