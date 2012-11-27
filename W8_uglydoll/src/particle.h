//
//  particle.h
//  W8_creaaature
//
//  Created by Jun Sik (Jason) Kim on 11/23/12.
//
//

#ifndef __W8_creaaature__particle__
#define __W8_creaaature__particle__

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        
        particle();
        virtual ~particle(){};
        
        void resetForce();
        void addForce(float x, float y);
        void addRepulsionForce(float x, float y, float radius, float scale);
        void addAttractionForce(float x, float y, float radius, float scale);
        
        void addRepulsionForce(particle &p, float radius, float scale);
        void addAttractionForce(particle &p, float radius, float scale);
        void addClockwiseForce(particle &p, float radius, float scale);
        void addCounterClockwiseForce(particle &p, float radius, float scale);
        
        
        void addDampingForce();
        
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
        
        void bounceOffWalls();
        
        bool  bFixed;
        
        float damping;
    
    protected:
    private:
};

#endif /* defined(__W8_creaaature__particle__) */
