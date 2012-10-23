//
//  windBlow.cpp
//  HW5_attractionrepulsion_audioinput
//
//  Created by Jun Sik (Jason) Kim on 10/20/12.
//
//

#include "windBlow.h"

void windBlow::setup() {
    
    bufferSize = 256;
    left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
}

void windBlow::update() {
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	volHistory.push_back( scaledVol );
}