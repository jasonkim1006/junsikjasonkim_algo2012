#pragma once

#include "ofMain.h"
#include "circles.h"
#include "circlestwo.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        #define NUM_CIRCLES 50
        circles mycircles[NUM_CIRCLES];
        circles mycircles2[NUM_CIRCLES];
        circlestwo mycircles3[NUM_CIRCLES];
        circlestwo mycircles4[NUM_CIRCLES];
		
};
