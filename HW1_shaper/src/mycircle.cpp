//
//  mycircle.cpp
//  HW1_shaper
//
//  Created by Jun Sik (Jason) Kim on 9/17/12.
//
//

#include "mycircle.h"

//------------------------------------------------------------------
mycircle::mycircle(){
	circleshaper = 1.0;
//    circleradius = 10;
    circlecolor.r=255;
    circlecolor.g=100;
    circlecolor.b=255;
    circlecolor.a=255;
}

//------------------------------------------------------------------
void mycircle::draw() {
	ofFill();
    ofSetColor(circlecolor);
    ofCircle(circlepos.x, circlepos.y, circleradius);
}


//------------------------------------------------------------------
void mycircle::interpolateByPct(float myCirclePct){
	circlepct = powf(myCirclePct, circleshaper);
    circleradius = powf(myCirclePct*10, circleshaper);
    circlecolor.r = powf(myCirclePct*255, circleshaper);
    circlecolor.a = powf(myCirclePct*255,circleshaper);
	circlepos.x = (1-circlepct) * circleposa.x + (circlepct) * circleposb.x;
	circlepos.y = (1-circlepct) * circleposa.y + (circlepct) * circleposb.y;
}