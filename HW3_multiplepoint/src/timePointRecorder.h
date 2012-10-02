//
//  timePointRecorder.h
//  HW3_multiplepoint
//
//  Created by Jun Sik (Jason) Kim on 10/1/12.
//
//

#ifndef __HW3_multiplepoint__timePointRecorder__
#define __HW3_multiplepoint__timePointRecorder__

#include "ofMain.h"
#include "timePoint.h"

class timePointRecorder {
    public:
    
    //boolean of recording = false 
    void    setup();
    //start new point vector
    void    clear();
    //draw the points stored in vector
    void    draw();
    
    //MOUSE PRESSED
    void    startDrawing(float x, float y);
    //MOUSE DRAGGED
    void    addPoint (float x, float y);
    //MOUSE RELEASED
    void    endDrawing();
    
    //get point values for the position relative to time it was drawn
    ofPoint getPositionForTime(float time);
    
    //JASON
    ofPoint getBehindPositionForTime(float time);
    
    //get point values for the velocity relative to time it was drawn
    ofPoint getVelocityForTime(float time);
    
    
    //has a line drawing (ready for circle drawing or sound)
    bool    bHaveADrawing();
    //get the duration (in f) of how long it took to complete one drawing cycle
    float   getDuration();
    
    //vector of timePoints to be drawn as line and for calculating time
    vector <timePoint> pts;
    //to measure the startTime of the drawing. Hence, the time always starts from 0. (ofGetElapsedTimef - startTime)
    float   startTime;
    //is it mousepressed? is it recording a time?
    bool    bRecording;


};


#endif /* defined(__HW3_multiplepoint__timePointRecorder__) */
