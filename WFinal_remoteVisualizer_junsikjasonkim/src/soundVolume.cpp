//
//  soundVolume.cpp
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/18/12.
//
//

#include "soundVolume.h"


void soundVolume::setup() {
    
    bufferSize = 256;
    left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
}

void soundVolume::update() {
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	volHistory.push_back( scaledVol );
}


