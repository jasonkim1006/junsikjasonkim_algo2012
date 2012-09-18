#pragma once

#include "ofMain.h"
#include "rectangle.h"
#include "mycircle.h"

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
        
        mycircle myCircles[10];
        mycircle myCircles1[10];
        mycircle myCircles2[10];
        rectangle myRectangles[10];
        float pct;
        float circlepct;
        float circlepct1;
        float circlepct2;
    
};
