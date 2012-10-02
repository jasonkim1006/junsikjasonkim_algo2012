//
//  timePointRecorder.cpp
//  HW3_multiplepoint
//
//  Created by Jun Sik (Jason) Kim on 10/1/12.
//
//

#include "timePointRecorder.h"


//-------------------------------------------------
void timePointRecorder::setup(){
    //initially not drawing anything
    //triggered to true in startDrawing function (mousepressed of testApp.cpp)
    bRecording = false;
}

//-------------------------------------------------
void timePointRecorder::clear(){
    //clear the vector (triggered at the beginning of startDrawing to get new values into the vector of points)
    pts.clear();
}

//-------------------------------------------------
void timePointRecorder::draw(){
    
    //line drawing
    ofSetColor(0,0,0);
    ofNoFill();
    
    ofBeginShape();
    for (int i = 0; i < pts.size(); i++){
        ofVertex(pts[i].x, pts[i].y);
    }
    ofEndShape();
    
}

//-------------------------------------------------
void timePointRecorder::startDrawing(float x, float y){
    //MOUSEPRESSED
    
    //clear what was previously inside the pts vector
    clear();
    //you are recording
    bRecording = true;
    //ofGetElapsedTimef() - startTime = 0... 1... 2... 3...
    startTime = ofGetElapsedTimef();
    //temporary timePoint that gets stored in the vector of pts.
    //x and y are mouseX and mouseY in testApp.cpp
    timePoint temp;
    temp.x = x;
    temp.y = y;
    temp.t = 0;
    //push the x,y values of mouse into the last container of the vector pts.
    pts.push_back(temp);

}

//-------------------------------------------------
void timePointRecorder::addPoint(float x, float y){
    //MOUSEDRAGGED
    
    timePoint temp;
    temp.x = x;
    temp.y = y;
    //calculating the amount of time passed by since the initial start of drawing (mousepressed)
    //and stores these time values into each ofPoint inside the vector
    temp.t = ofGetElapsedTimef() - startTime;
    pts.push_back(temp);
    
}

//-------------------------------------------------
void timePointRecorder::endDrawing(){
    //MOUSERELEASED
    
    //not drawing anymore so end the recording of drawing
    bRecording = false;
}

//-------------------------------------------------
bool timePointRecorder::bHaveADrawing(){
    //RETURNS A BOOL (NOT VOID)
    
    if (bRecording ==true){
    //if you are drawing (mouse dragging)
        return false;
        //bHaveADrawing = false
    }
    else if (pts.size()<2){
        return false;
        //bHaveADrawing = false
    }
    
    //if you are not drawing, and if the pts vector size is greater or equal to 2, return true.
    //will not reach until this return value if any of the previous two are true.
    return true;
}

//-------------------------------------------------
float timePointRecorder::getDuration(){
    //RETURNS A FLOAT
    
    float duration = 0;
    if(bHaveADrawing() == true){
    //if there is a drawing
        duration = pts[pts.size()-1].t;
        //duration equals the time (duration) of the last element drawn into the vector pts.
        //pts[0] = 1st point, hence pts.size()-1 = last point (pts[19] = 20th point)
    }
    return duration;
    //returns the time it took to draw until last point
}

//-------------------------------------------------
ofPoint timePointRecorder::getPositionForTime(float time){
    //FOR GETTING X,Y COORDINATES IN BETWEEN POINTS
    
    if(bHaveADrawing() == false){
    //if there is no drawing
        return ofPoint(0,0,0);
        //you will see the circle at points (0,0) if there is no drawing
    }
    
    //figuring out where we are in the drawing using time
    ofPoint pos;
    
    for (int i = 0; i < pts.size()-1; i++){
        if(time >= pts[i].t && time <= pts[i+1].t){
        //if time is in between one point and next point
            
            //CALCULATE PCT
            float part = time - pts[i].t;
            float whole = pts[i+1].t - pts[i].t;
            float pct = part / whole;
            /*
             percentage is always the part divided by the whole, so if we have time t,
             and A.t and B.t which are between, percentage =
             
             (t - A.t)  / (B.t - A.t)
             */
            
            //percentage formula
            pos.x = (1-pct) * pts[i].x + (pct) * pts[i+1].x;
            pos.y = (1-pct) * pts[i].y + (pct) * pts[i+1].y;
            //(pos.x, pos.y) is the point in between pts[i] and pts[i+1] relative to percentage
            
//            posback.x = (1-pct) * pts[i-1].x + (pct) * pts[i].x;
//            posback.y = (1-pct) * pts[i-1].y + (pct) * pts[i].y;
            
        }
    }
    
    return pos;

}

//-------------------------------------------------
ofPoint timePointRecorder::getBehindPositionForTime(float time){
    if(bHaveADrawing() == false){
        return ofPoint(0,0,0);
//        return ofPoint(pts[3].x,pts[3].y,0);
    }
    
    
    //figuring out where we are in the drawing using time
    ofPoint posbehind;
    
    for (int i = 0; i < pts.size()-1; i++){
        
        if(time >= pts[i].t && time <= pts[i+1].t){
            //if time is in between one point and next point
            
            //CALCULATE PCT
            float part = time - pts[i].t;
            float whole = pts[i+1].t - pts[i].t;
            float pct = part / whole;
            /*
             percentage is always the part divided by the whole, so if we have time t,
             and A.t and B.t which are between, percentage =
             
             (t - A.t)  / (B.t - A.t)
             */
            
            
            //percentage formula
            posbehind.x = (1-pct) * pts[i-5].x + (pct) * pts[i-4].x;
            posbehind.y = (1-pct) * pts[i-5].y + (pct) * pts[i-4].y;
            
            if (posbehind.x <= pts[0].x){
                posbehind.x = pts[0].x;
            }
            
            if (posbehind.y <= pts[0].y){
                posbehind.y = pts[0].y;
            }


            //(pos.x, pos.y) is the point in between pts[i] and pts[i+1] relative to percentage
            
            //            posback.x = (1-pct) * pts[i-1].x + (pct) * pts[i].x;
            //            posback.y = (1-pct) * pts[i-1].y + (pct) * pts[i].y;
            
        }
    }
    
    return posbehind;
    
}

//-------------------------------------------------
ofPoint timePointRecorder::getVelocityForTime(float time){
    //DETERMINING VELOCITY (MOVEMENT OF MOUSE) BETWEEN TWO POINTS
    
    /*
     to get the velcoity, look back a bit of time (in this case time - 0.09f), and at the current time
     and get the difference
     velocity = pos at time 1 - pos at time 0...
     */
    
    ofPoint prevPt = getPositionForTime(MAX(time-0.09f,0)); //0.09 secs ago -> its 0 if lower than 0 (MAX)
    ofPoint currPt = getPositionForTime(time);
    
    ofPoint diff;
    diff.x = currPt.x - prevPt.x;
    diff.y = currPt.y - prevPt.y;
    
    return diff;
}

