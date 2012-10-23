//
//  windBlow.h
//  HW5_attractionrepulsion_audioinput
//
//  Created by Jun Sik (Jason) Kim on 10/20/12.
//
//

#ifndef __HW5_attractionrepulsion_audioinput__windBlow__
#define __HW5_attractionrepulsion_audioinput__windBlow__

#include "ofMain.h"


class windBlow{
    
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

#endif /* defined(__HW5_attractionrepulsion_audioinput__windBlow__) */
