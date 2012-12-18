//
//  soundVolume.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/18/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__soundVolume__
#define __remoteMusicVisualizer_junsikjasonkim__soundVolume__

#include <iostream>
#include "ofMain.h"

class soundVolume{
    
public:
    
    void setup();
    void update();
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int bufferCounter;
    int drawCounter;
    int bufferSize;
    
    int ballX;
    int ballY;
    
    float smoothedVol;
    float scaledVol;
    float angle;
    
};

#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__soundVolume__) */
