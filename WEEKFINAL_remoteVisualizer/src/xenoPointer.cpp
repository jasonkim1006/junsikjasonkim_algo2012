//
//  xenoPointer.cpp
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/10/12.
//
//

#include "xenoPointer.h"

//------------------------------------------------------------------
xenoPointer::xenoPointer(){
    catchUpSpeed = 0.1f;
    xenoRadius = 20;
}

//------------------------------------------------------------------
void xenoPointer::draw(){
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofCircle(pos.x, pos.y, xenoRadius);
}

//------------------------------------------------------------------
void xenoPointer::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}