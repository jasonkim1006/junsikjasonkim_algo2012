#pragma once

#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"

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
    
        vector <particle> particles;
        vector <particle> particlesTwo;
        vectorField VF;
    
        float prevMouseX;
        float prevMouseY;
    
        float mySine;
        int drawingStyle;
        bool bFade;

};
