#pragma once

#include "ofMain.h"
#include "RazorAHRS.h"
#include "xenoPointer.h"
#include "baseScene.h"
#include "channelOne.h"
#include "channelTwo.h"
#include "channelThree.h"
#include "particletwo.h"

#define BUFFER_SIZE 512
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
        void audioReceived (float *input, int bufferSize, int nChannels);

        //Channels
        vector < baseScene * > scenes;
        int sceneNumber;
    
        //IMRemote
        RazorAHRS *razor;
        const string serial_port_name = "/dev/tty.usbserial-FTFNV8XJ";
        float xYaw;
        float yPitch;
        float zRoll;
        float yawOffset; //calibrating gyroscope
        float imuSpeed;
        string imuData;
    
        ofTrueTypeFont myFont;
        ofTrueTypeFont mySmallFont;
        bool bFullScreen;
    
        //Particle for FFT
        vector <particletwo> myparticles;    
        bool    bRepel;
        float   radius;
        float   strength;
    


};
