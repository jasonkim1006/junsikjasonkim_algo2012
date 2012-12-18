//
//  particletwo.h
//  remoteMusicVisualizer_junsikjasonkim
//
//  Created by Jun Sik (Jason) Kim on 12/12/12.
//
//

#ifndef __remoteMusicVisualizer_junsikjasonkim__particletwo__
#define __remoteMusicVisualizer_junsikjasonkim__particletwo__

#include <iostream>
#include "ofMain.h"

class particletwo
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        
        particletwo();
        virtual ~particletwo(){};
        
        void resetForce();
        void addForce(float x, float y);
        void addRepulsionForce(float x, float y, float radius, float scale);
        void addAttractionForce(float x, float y, float radius, float scale);
        
        void addRepulsionForce(particletwo &p, float radius, float scale);
        void addAttractionForce(particletwo &p, float radius, float scale);
        void addClockwiseForce(particletwo &p, float radius, float scale);
        void addCounterClockwiseForce(particletwo &p, float radius, float scale);
        
        
        void addDampingForce();
        
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
        
        void bounceOffWalls();
        
        bool  bFixed;
        
        float damping;
    
        ofColor myColor;
    
    protected:
    private:
};


#endif /* defined(__remoteMusicVisualizer_junsikjasonkim__particletwo__) */
